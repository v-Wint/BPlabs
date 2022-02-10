from module import *

def main():
    name1 = "file1.txt"
    name2 = "file2.txt"

    create_file(name1)
    create_new_file(name1, name2)

    display_file(name1)
    display_file(name2)

if __name__ == "__main__":
    main()