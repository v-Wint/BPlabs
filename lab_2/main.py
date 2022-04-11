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

    display_spare_time_list(get_task_list(spare_time_path))

if __name__ == "__main__":
    main()

