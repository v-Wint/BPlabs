import sys

def get_user_input() -> str:
    """Turn the user's input into the text

    The input ends when a control character is entered
    """

    text = ""
    print("Enter your text, type any control character when finished")
    try:    #some of the control characters return error, handle it, the line is not gonna be saved
        while True:
            line = input()
            for c in line:
                if ord(c) > 31:    #if not a control char
                    text += c
                else:
                    return text    #exit
            text += '\n'
    except BaseException:
        return text
    

def create_file(name) -> None:
    """Create a file from the user input
    The input ends when a control character is entered

    Parameters
    ----------
    name : str
        The path to the file to be created
    """

    try:    # handle file opening errors
        with open(name, 'w') as f:
            f.write(get_user_input())
    except OSError:
        print(f"Error: file \"{name}\" could not be opened")
        sys.exit(1)

def create_new_file(name1, name2) -> None:
    """Create a new file getting the lines of the orig file and putting the first character of the last word in them in the beginning

    Parameters
    ----------
    name1 : str
        The path to the original file
    name2 : str
        The path to the file to be created
    """

    # handle file opening errors
    try:
        with open(name1, 'r') as inf:
            with open(name2, 'w') as outf:
                for line in inf.readlines():
                    if line.strip():    # check if not a blank line
                        line = line.strip().split()[-1][0] + line    #the first character of the last word in a line
                    outf.write(line)
    except OSError:
        print(f"Error: file \"{name1}\" or \"{name2}\" could not be opened")
        sys.exit(1)

def display_file(name) -> None:
    """Display the text in the file

    Parameters
    ----------
    name : str
        The path to the file
    """

    try:
        with open(name, 'r') as f:
            print('\n' + '-'*10 + name + '-'*10)
            print(f.read())
            print('-'*(20  + len(name)) + '\n')
    except OSError:
        print(f"Error: file \"{name}\" could not be opened")
        sys.exit(1)
