SRC_FILE = r".\ex2\member_list.txt"
DST_FILE = r".\ex2\member_list_out.txt"
K = 20
AGE = 2
NAME = 1
SEMESTER = 4
S = 5

def printYoungestStudents(in_file_path: str, out_file_path: str, k: int):
    if type(k) is not int or k < 1:
        return -1
    fileCorrect(in_file_path, out_file_path)
    with open(out_file_path,"r") as rfile:
        members = rfile.readlines()
        if (len(members) < k):
            k = len(members)
        members.sort()
        members.sort(key=lambda member: int((member.split(","))[AGE].strip(" ")))
        with open(out_file_path, "w") as wfile:
            for member in members[:k]:
                wfile.write((member.split(","))[NAME] + "\n")
    return k


def correctAgeAvg(in_file_path: str, semester: int):
    if type(semester) is not int or semester < 1 :
        return -1
    #fileCorrect(in_file_path, out_file_path)
    with open(in_file_path,"r") as rfile:
        counter, total_age = 0, 0
        for member in rfile:
            member_seperated = member.split(",")
            print
            if int(member_seperated[SEMESTER].strip()) == semester:
                counter += 1
                total_age += int(member_seperated[AGE])
        if counter is 0:
            return 0
        return float(total_age) / counter


if __name__ == "__main__":
    print(printYoungestStudents(SRC_FILE, DST_FILE, K))
    print(correctAgeAvg(SRC_FILE,S))
