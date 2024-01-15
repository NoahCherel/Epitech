import os
import time
import argparse
import glob

def remove_exe_log():
    for extension in ['exe', 'log']:
        for file_path in glob.glob(f'*.{extension}'):
            os.remove(file_path)

def compile_code(files):
    files_list = " ".join(files)

    if os.path.exists("pbrain-gomoku-ai.exe"):
        os.remove("pbrain-gomoku-ai.exe")
    time.sleep(1)
    os.system("pip install pyinstaller")
    os.system(f"python -m PyInstaller -F {files_list} -n pbrain-gomoku-ai.exe")
    os.system("copy dist\\pbrain-gomoku-ai.exe .")
    os.system("rmdir /s /q build")
    os.system("rmdir /s /q dist")
    if os.path.exists("pbrain-gomoku-ai.exe"):
        os.remove("pbrain-gomoku-ai.exe.spec")

def main():
    parser = argparse.ArgumentParser(description='Compile and optionally remove .exe and .log files.')
    parser.add_argument('-rm', action='store_true', help='Remove .exe and .log files')
    args = parser.parse_args()
    if args.rm:
        remove_exe_log()
    else:
        compile_code(["pbrain-gomoku-ai"])

if __name__ == "__main__":
    main()
