# name modification
def change_name(student, name):
    student[0] = name

if __name__ == "__main__":
    student = ["ab", 20]
    change_name(student, "b")
    print(student)