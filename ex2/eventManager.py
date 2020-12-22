SRC_FILE = r".\ex2\member_list.txt"
DST_FILE = r".\ex2\member_list_out.txt"
K = 4


def printYoungestStudents(in_file_path: str, out_file_path: str, k: int):
    #fileCorrect(in_file_path, out_file_path)
    file_in = open(in_file_path,"r")
    file_out = open(out_file_path,"w")
    stream = file_in.read()
    print(stream)
    file_out.write(stream)
    file_out.close()
    file_in.close()

if __name__ == "__main__":
    printYoungestStudents(SRC_FILE, DST_FILE, K)