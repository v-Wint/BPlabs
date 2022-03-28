from module import *

def main():
    task_list_path = "tasklist.bin"
    spare_time_path = "sparelist.bin"

    create_task_list(task_list_path)

    task_list = get_task_list(task_list_path)
    task_list = sort_task_list(task_list)
    print("\nList of tasks:")
    display_task_list(task_list)

    find_the_nearest_task(task_list)

    create_spare_time_list(task_list, spare_time_path)

    task_list = get_task_list(spare_time_path)
    if task_list:
        print("\nSpare time after 13:00")
        display_task_list(task_list)
    else:
        print("\nNo spare time after 13:00")

if __name__ == "__main__":
    main()
