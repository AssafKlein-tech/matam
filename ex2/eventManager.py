SRC_FILE = r".\ex2\member_list.txt"
DST_FILE = r".\ex2\member_list_out.txt"
K = 4


def printYoungestStudents(in_file_path: str, out_file_path: str, k: int):
    #fileCorrect(in_file_path, out_file_path)
    if k < 1:
        return -1
    with open(in_file_path,"r") as rfile:
        members = rfile.readlines()
        members.sort()
        members.sort(key=lambda member: int((member.split(","))[2].strip(" ")))
        with open(out_file_path, "w") as wfile:
            wfile.writelines(members[:k])
    return 1

if __name__ == "__main__":
    printYoungestStudents(SRC_FILE, DST_FILE, K)