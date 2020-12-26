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
         if int(students_dict['id'][i])/100000000==0 or not students_dict['name'][i].isalpha() or 16<int(students_dict['age'][i])<120 or 2020-int(students_dict['age'][i])==int(students_dict['year of birth'][i]) or int(students_dict['semester'][i])>0 :
            students_dict['id'].pop(i)
            students_dict['name'].pop(i)
            students_dict['age'].pop(i)
            students_dict['year of birth'].pop(i)
            students_dict['semester'].pop(i)
 
if __name__ == "__main__":
    fileCorrect(SRC_FILE, DST_FILE)


