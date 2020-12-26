SRC_FILE = r".\ex2\member_list.txt"
DST_FILE = r".\ex2\member_list_out.txt"
K = 20
AGE = 2
NAME = 1


def printYoungestStudents(in_file_path: str, out_file_path: str, k: int):
    if k < 1:
        return -1
    #fileCorrect(in_file_path, out_file_path)
    with open(in_file_path,"r") as rfile:
        members = rfile.readlines()
        if (len(members) < k):
            k = len(members)
        members.sort()
        members.sort(key=lambda member: int((member.split(","))[AGE].strip(" ")))
        with open(out_file_path, "w") as wfile:
            for member in members[:k]:
                wfile.write((member.split(","))[NAME] + "\n")
    return k

if __name__ == "__main__":
    print(printYoungestStudents(SRC_FILE, DST_FILE, K))