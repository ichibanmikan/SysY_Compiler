import argparse
import os
import sys
import subprocess
assert ('linux' in sys.platform)
outfile = './out/'
syfiles = './test/'

error = '\033[1;31;40m%s\033[0m'
info = '\033[1;32;40m%s\033[0m'
warning = '\033[1;34;40m%s\033[0m'

def get_args():
	parser = argparse.ArgumentParser()

	parser.add_argument('-e',
						'--outfile',
						default=outfile,
						type=str,
						help='The Executable for testing (default: '+ outfile + ')')
	parser.add_argument('-s',
						'--syfiles',
						default=syfiles,
						type=str,
						help='Test cases for testing (default: '+ syfiles + ')')
	parser.add_argument('-y',
						'--onlysy',
						default=True,
						action='store_false',
						help='Consider only test files ending in sy')
	parser.add_argument('-p',
						'--print_stdout',
						default=False,
						action='store_true',
						help='Print standard output')


	args = parser.parse_args() 
	return args

def parse_exe(exepath):
	exename = ''
	if(os.path.isdir(exepath)):
		filelists = os.listdir(exepath)
		exenum = 0
		for filename in filelists:
			if(os.path.isfile(exepath+filename)):
				exenum += 1
				exename = exepath+filename
		try:
			assert(exenum == 1)
		except AssertionError as aeeor:
			print(error%'[Error]',end=' ')
			print('Please make sure there is only one executable in the path.\
				', aeeor, aeeor.__str__())
			exit()
	else:
		exename = exepath
	try:
		assert(os.path.exists(exename))
	except AssertionError as aeeor:
		print(error%'[Error]',end=' ')
		print('File does not exist.', aeeor, aeeor.__str__())
		exit()
	print(info%'[Info]',end=' ')
	print('The executable to be executed is',exename)
	return exename

def test_files(testfile,onlysy):
	testcases = []
	if(os.path.isdir(testfile)):
		syfilelists = os.listdir(testfile)
		for syfile in syfilelists:
			if(onlysy and (not '.sy' in syfile)):
				continue
			testcases.append(testfile+syfile)
	else:
		testcases.append(testfile)
	try:
		assert(len(testcases)>0)
	except:
		print(error%'[Error]',end=' ')
		print('No test case.')
		exit()
	print(info%'[Info]',end=' ')
	print('Number of test cases:',len(testcases))
	return testcases

def run_single(exe_path,testcase):
	cmd = exe_path+' '+testcase
	p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	stdout, stderr = p.communicate()
	return stdout, stderr

def main():		
	args = get_args()
	exe_path = parse_exe(args.outfile)
	testcases = test_files(args.syfiles,args.onlysy)
	for testcase in testcases:
		print(info%'[Info]',end=' ')
		print('Running test cases:',testcase)
		stdout, stderr = run_single(exe_path,testcase)
		if(stderr):
			print(error%'[Error]',end=' ')
			print('testcase:'+testcase)
			print(stderr.decode('utf-8'))
		else:
			print('>'+testcase+' pass...')
		if(args.print_stdout):
			print(stdout.decode('utf-8'))


if __name__ == "__main__":
	main()
