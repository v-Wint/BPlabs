from datetime import datetime as dt
class Task(object):
    name: str
    start_time: int
    duration: int
    end_time: int

def write_to_file(f, *args) -> None:
    '''Write args to the file one by one

    Parameters
    ----------
    file : <_io.BufferedWriter>
        Python file object to write
    args : list, optional
        Values to write 
    '''

    for arg in args:
        if isinstance(arg, str):
            arg = arg + '\0'*(100-len(arg)) #100 bytes
            f.write(bytes(arg.encode()))
        elif isinstance(arg, int):
            f.write(arg.to_bytes(4, byteorder='big')) #4 bytes

def create_task_list(file_name) -> None:
    '''Write a number of tasks to file
    The user is asked information about: number of tasks, 
    name of each task, start time of each task, duration of each task.
    Name, start time, duration and end time of the tasks are written
    
    Parameters
    ----------
    file_name : str
        The path to the file
    '''
    while True:
        try:
            n = int(input("Enter number of tasks: "))
        except ValueError: 
            pass
        else:
            break

    with open(file_name, 'wb') as f:
        for i in range(1, n+1):

            # task name
            while True:
                s = input(f"({i}) Task name: ")
                if len(s) < 100:
                    break

            # start time
            while True:
                try:
                    h, m = input("Time of start (seaparate hours and minutes with space): ").split(' ')
                    h, m = int(h), int(m)
                    if h >= 0 and h < 24 and m >= 0 and m < 60:
                        break
                except ValueError:
                    pass
                    
            start_time = h * 60 + m

            # duration
            while True:
                try:
                    h, m = input("Duration (seaparate hours and minutes with space): ").split(' ')
                    h, m = int(h), int(m)
                    if h >= 0 and h < 24 and m >= 0 and m < 60:
                        break
                except ValueError:
                    pass

            duration = h * 60 + m
            end_time = start_time + duration

            write_to_file(f, s, start_time, duration, end_time)

def display_task(task) -> None:
    '''Print out task information'''

    print("{:>15s}:   {:02d}:{:02d}--->{:02d}:{:02d}--->{:02d}:{:02d}".format(
          task.name, 
          task.start_time // 60, 
          task.start_time % 60,
		  task.duration // 60, 
          task.duration % 60,
		  task.end_time // 60, 
          task.end_time % 60));

def display_task_list(task_list) -> None:
    '''Print out information of tasks from task list'''

    for task in task_list:
        display_task(task)

def get_task_list(file_name) -> list:
    '''Read tasks from a file and create a list of them

    Parameters
    ----------
    file_name : str
        The path to the file to read

    Returns
    ----------
    task_list : list
        list of tasks
    '''

    task_list = []
    with open(file_name, 'rb') as f:
        while True:
            task = Task()
            task.name = f.read(100).decode().rstrip('\0')
            if not task.name: # if not eof
                break
            task.start_time = int.from_bytes(f.read(4), byteorder='big')
            task.duration = int.from_bytes(f.read(4), byteorder='big')
            task.end_time = int.from_bytes(f.read(4), byteorder='big')
            task_list.append(task)
    return task_list


def sort_task_list(task_list) -> list:
    '''Get sorted task lsit by the start time'''
    return sorted(task_list, key = lambda task : task.start_time)

def find_the_nearest_task(task_list) -> None:
    '''Find the nearest task after the current time
    Print out information about that task
    '''

    local_time = dt.now()
    current_time = local_time.hour*60 + local_time.minute
    
    for task in task_list:
        if task.start_time > current_time:
            print("\nCurrent time: {:02d}:{:02d}".format(
                local_time.hour, local_time.minute))
            print("The next task is:")
            display_task(task)
            return

    print("\nYou've got no task left")

def create_spare_time_list(task_list, spare_time_path) -> None:
    '''Write to the file a number of tasks in which each task represents the spare time after 13:00

    Parameters
    ----------
    task_list : list
        list of current tasks
    spare_time_path : str
        path to the file to write
    '''
    with open(spare_time_path, 'wb') as f:
        for i in range(len(task_list)-1):
            current_task = task_list[i]
            next_task = task_list[i+1] 

            a = current_task.start_time
            b = current_task.end_time
            if b >= 13*60: #if ends after 13:00
                if a > 13*60: #check if there is spare time after 13:00, if so, add additional spare time interval
                    write_to_file(f, "spare", 13*60, a - 13*60, a)

                a = current_task.end_time
                b = next_task.start_time
                if b - a > 0 : #get the last task and check if there is spare time before 24:00
                    write_to_file(f, "spare", a, b - a, b)

        b = task_list[-1].end_time
        if b < 24*60:
            if b > 13*60:
                write_to_file(f, "spare", b, 24*60 - b, 24*60)
            else:
                write_to_file(f, "spare", 13*60, 11 * 60, 24 * 60)
