#### IMPORTS ####
import event_manager as EM

AGE = 2
NAME = 1
SEMESTER = 4
DATES = 2

<<<<<<< HEAD
#fills the dictionary with data from the stream
=======
# fills the dictionary with data from the stream
# stream: the string which created from the input file.
# student_dict: the dictionary of the students.
>>>>>>> 937c1c16aa7b75485e82d7658e56d76252eedcf7
def fillDict(stream: str,students_dict:dict):
    one_line_stream = stream.replace('\n',',')
    one_line_stream_no_space = " ".join(one_line_stream.split())
    student_data_list = one_line_stream_no_space.split(',')
    student_data_list_no_space = [student_data.strip() for student_data in student_data_list]
    students_dict['id'] = student_data_list_no_space[0::5]
    students_dict['name'] = student_data_list_no_space[1::5]
    students_dict['age'] = student_data_list_no_space[2::5]
    students_dict['year of birth'] = student_data_list_no_space[3::5]
    students_dict['semester'] = student_data_list_no_space[4::5]

<<<<<<< HEAD
#removes a member from the dictionary
=======
# removes member from the dictionary
# student_dict: the dictionary of the students.
# i: index of member to remove.
>>>>>>> 937c1c16aa7b75485e82d7658e56d76252eedcf7
def removeMember(students_dict:dict, i:int):
    students_dict['id'][i] = None
    students_dict['name'][i] = None
    students_dict['age'][i] = None
    students_dict['year of birth'][i] = None
    students_dict['semester'][i] = None

<<<<<<< HEAD
#organizes the dictionary - removes not legal members and duplications 
=======
# removes non legal members from the dictionary and duplications
# student_dict: the dictionary of the students.
>>>>>>> 937c1c16aa7b75485e82d7658e56d76252eedcf7
def organizeDict(students_dict:dict):
    for i in range(len(students_dict['id'])):
        if  students_dict['id'][i].lstrip("-").isdigit() and students_dict['age'][i].lstrip("-").isdigit() \
            and students_dict['year of birth'][i].lstrip("-").isdigit() \
                and  students_dict['semester'][i].lstrip("-").isdigit():
            if  int(students_dict['id'][i]) // 10000000 == 0 or int(students_dict['id'][i]) > 99999999 \
                or not students_dict['name'][i].replace(' ','').isalpha() or not 16<=int(students_dict['age'][i])<=120 \
                    or not  2020 - int(students_dict['age'][i]) == int(students_dict['year of birth'][i]) \
                        or not int(students_dict['semester'][i]) > 0 :
                removeMember(students_dict,i)
    if len(students_dict['id']) > 1:
        for i in range(len(students_dict['id'])-1, -1, -1):
            for j in range(i-1, -1, -1):
                if students_dict['id'][i] == students_dict['id'][j] and students_dict['id'][i] != None:
                    removeMember(students_dict,j)

#transfers the data from the dictionary to a string
<<<<<<< HEAD
=======
# student_dict: the dictionary of the students.
# final_string: the string which get the data from the dictionary 
>>>>>>> 937c1c16aa7b75485e82d7658e56d76252eedcf7
def dictTostring(students_dict:dict,final_string:str):
    sorted_id_list = students_dict['id'].copy()
    sorted_id_list = [int(i) for i in students_dict['id'] if i!=None and i.isdigit()]
    sorted_id_list.sort() 
    for id in sorted_id_list:
         for i in range(len(students_dict['id'])-1,-1,-1):
             if students_dict['id'][i]!=None and students_dict['id'][i].isdigit() and id==int(students_dict['id'][i]):
                final_string += students_dict['id'][i]+', '+students_dict['name'][i]+', '+students_dict['age'][i]+', '+\
                    students_dict['year of birth'][i]+', '+students_dict['semester'][i]+'\n'
    return final_string

<<<<<<< HEAD
#corrects a string
=======
# corrects the string by the demmands of the task 
# stream: the string which created from the input file.
>>>>>>> 937c1c16aa7b75485e82d7658e56d76252eedcf7
def stringCorrect(stream: str):
    students_dict = {
        'id':[],
        'name':[],
        'age':[],
        'year of birth':[],
        'semester':[]
    }
    fillDict(stream,students_dict)
    organizeDict(students_dict)
    final_string = ""
    final_string = dictTostring(students_dict,final_string)   
    return final_string


#### PART 1 ####
# Filters a file of students' subscription to specific event:
#   orig_file_path: The path to the unfiltered subscription file
#   filtered_file_path: The path to the new filtered file
def fileCorrect(orig_file_path: str, filtered_file_path: str):
    file_in = open(orig_file_path,"r")
    file_out = open(filtered_file_path,"w")
    stream = file_in.read()
    data_to_write = stringCorrect(stream)
    file_out.write(data_to_write)
    file_out.close()
    file_in.close()


# Writes the names of the K youngest students which subscribed 
# to the event correctly.
#   in_file_path: The path to the unfiltered subscription file
#   out_file_path: file path of the output file
def printYoungestStudents(in_file_path: str, out_file_path: str, k: int) -> int:
    if type(k) is not int or k < 1:
        return -1
    with open(in_file_path, "r") as input_file:
        members = stringCorrect(input_file.read()).strip().split("\n")
    if members[0] == '':
        out_file = open(out_file_path, "w")
        out_file.close()
        return 0
    if (len(members) < k):
        k = len(members)
    members.sort()
    members.sort(key=lambda member: int((member.split(","))[AGE].strip(" ")))
    with open(out_file_path, "w") as out_file:
        for member in members[:k]:
            out_file.write((member.split(","))[NAME].strip() + "\n")
    return k

# Calculates the avg age for a given semester
#   in_file_path: The path to the unfiltered subscription file
#   retuns the avg, else error codes defined.
def correctAgeAvg(in_file_path: str, semester: int) -> float:
    if type(semester) is not int or semester < 1 :
        return -1
    with open(in_file_path, "r") as input_file:
        corrected_file_stream = stringCorrect(input_file.read())
    counter, total_age = 0, 0
    corrected_file_stream = corrected_file_stream.strip()
    for member in corrected_file_stream.split("\n"):
        member_seperated = member.split(",")
        if int(member_seperated[SEMESTER].strip()) == semester:
            counter += 1
            total_age += int(member_seperated[AGE])
    if counter == 0:
        return 0
    return float(total_age) / counter

# return the earliest date in the events list
#   events: list of dictionaries
#   retuns the earliest date 
def getMinDate(events :list):
    dates = list(zip(*[j.values() for j in events]))[DATES]
    min_date = dates[0]
    for date in dates:
        if EM.dateCompare(min_date, date) > 0:
            min_date = date
    return min_date

#### PART 2 ####
# Use SWIG :)
# print the events in the list "events" using the functions from hw1
#   events: list of dictionaries
#   file_path: file path of the output file
def printEventsList(events :list,file_path :str): #em, event_names: list, event_id_list: list, day: int, month: int, year: int):
    min_date = getMinDate(events)
    em = EM.createEventManager(min_date)
    for event in events:
        EM.emAddEventByDate(em,event["name"],event["date"],int(event["id"]))
    EM.emPrintAllEvents(em, file_path)
    return em

def testPrintEventsList(file_path :str):
    events_lists=[{"name":"New Year's Eve","id":1,"date": EM.dateCreate(30, 12, 2020)}, \
                    {"name" : "annual Rock & Metal party","id":2,"date":  EM.dateCreate(21, 4, 2021)}, \
                                 {"name" : "Improv","id":3,"date": EM.dateCreate(13, 3, 2021)}, \
                                     {"name" : "Student Festival","id":4,"date": EM.dateCreate(13, 5, 2021)},    ]
    em = printEventsList(events_lists,file_path)
    for event in events_lists:
        EM.dateDestroy(event["date"])
    EM.destroyEventManager(em)

#### Main #### 
# feel free to add more tests and change that section. 
# sys.argv - list of the arguments passed to the python script
if __name__ == "__main__":
    import sys
    if len(sys.argv)>1:
        testPrintEventsList(sys.argv[1])
