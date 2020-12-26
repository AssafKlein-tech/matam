SRC_FILE = r".\ex2\member_list.txt"
DST_FILE = r".\ex2\member_list_out.txt"
K = 20
AGE = 2
NAME = 1
SEMESTER = 4
S = 6

def fileCorrect(in_file_path: str, out_file_path: str):
    students_dict={
        'id':[],
        'name':[],
        'age':[],
        'year of birth':[],
        'semester':[]
    }
    file_in = open(in_file_path,"r")
    file_out = open(out_file_path,"w")
    stream = file_in.read()
    one_line_stream=stream.replace('\n',',')
    one_line_stream_no_space=" ".join(one_line_stream.split())
    student_data_list=one_line_stream_no_space.split(',')
    student_data_list_no_space= [student_data.strip() for student_data in student_data_list]
    students_dict['id']=student_data_list_no_space[0::5]
    students_dict['name']=student_data_list_no_space[1::5]
    students_dict['age']=student_data_list_no_space[2::5]
    students_dict['year of birth']=student_data_list_no_space[3::5]
    students_dict['semester']=student_data_list_no_space[4::5]
   
    for i in range(len(students_dict['id'])):
        if int(students_dict['id'][i])//10000000==0 or not students_dict['name'][i].replace(' ','').isalpha() or not 16<int(students_dict['age'][i])<120 or not 2020-int(students_dict['age'][i])==int(students_dict['year of birth'][i]) or not int(students_dict['semester'][i])>0 :
            students_dict['id'][i]=None
            students_dict['name'][i]=None
            students_dict['age'][i]=None
            students_dict['year of birth'][i]=None
            students_dict['semester'][i]=None
    
    if len(students_dict['id'])>1:
        for i in range(len(students_dict['id'])-1,0,-1):
            for j in range(i-1,-1,-1):
                if students_dict['id'][i]== students_dict['id'][j] and students_dict['id'][i]!=None:
                    students_dict['id'][j]=None
                    students_dict['name'][j]=None
                    students_dict['age'][j]=None
                    students_dict['year of birth'][j]=None
                    students_dict['semester'][j]=None

    sorted_id_list=students_dict['id'].copy()
    sorted_id_list = [int(i) for i in sorted_id_list if i!=None ]
    sorted_id_list.sort()     

    for id in sorted_id_list:
         for i in range(len(students_dict['id'])-1,0,-1):
             if students_dict['id'][i]!=None and id==int(students_dict['id'][i]):
                file_out.write(students_dict['id'][i]+', '+students_dict['name'][i]+', '+students_dict['age'][i]+', '+students_dict['year of birth'][i]+', '+students_dict['semester'][i]+'\n')

    file_out.close()
    file_in.close()

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
