#include <iostream>
using namespace std;

struct students {
    string Class;
    string name;
    string studentCode;
    students *next;
};

students *createStudents(string Class, string name, string studentCode) {
    students *temp = new students;
    temp->Class = Class;
    temp->name = name;
    temp->studentCode = studentCode;
    temp->next = NULL;
    return temp;
}

students *addStudents(students *Student, string Class, string name, string studentCode) {
    students *temp = new students;
    temp->Class = Class;
    temp->name = name;
    temp->studentCode = studentCode;
    temp->next = Student;
    Student = temp;
    return Student;
}
void printStudent (students *Student) {
    students *temp = Student;
    int ordinalNumber = 1;
    if(temp == NULL) {
        cout << "Danh sach hoc sinh rong. " << endl;
        cout << "-----------------------------" << endl;
    }
    while (temp != NULL) {
        cout << "So thu tu: " << ordinalNumber << endl;
        cout << "Ho va ten: " << temp->name << endl;
        cout << "Lop: " << temp->Class << endl;
        cout << "Ma so sinh vien: " << temp->studentCode << endl;
        cout << "-----------------------------" << endl;
        temp = temp->next;
        ordinalNumber++;
    }
}
students *updateStudentByName(students *Student, string studentCode1, string Class, string name, string studentCode2) {
    students *p = Student;
    bool found = false;
    while (p != NULL) {
        if (p->studentCode == studentCode1) {
            p->Class = Class;
            p->name = name;
            p->studentCode = studentCode2;
            found = true;
            break;
        }
        p = p->next;
    }

    if (!found) {
        cout << "Khong tim thay hoc sinh can sua, vui long kiem tra lai ma so sinh vien." << endl;
    }
    return Student;
}

    students *updateStudentByOrdinalNumber(students *Student, string studentCode, string Class, string name, int ordinalNumber) {
        students *p = Student;
        bool found = false;
        for (int i = 1; i < ordinalNumber; i++) {
            p = p->next;
        }
                p->Class = Class;
                p->name = name;
                p->studentCode = studentCode;
        return Student;
    }

students *deleteStudentByCode(students *Student, string studentCode) {
    if (Student != NULL && Student->studentCode == studentCode) {
        students *temp = Student;
        Student = Student->next;
        delete(temp);
        return Student;
    }

    students *prev = Student;
    students *current = Student->next;

    while (current != NULL) {
        if (current->studentCode == studentCode) {
            prev->next = current->next;
            delete(current);
            return Student;
        }
        prev = current;
        current = current->next;
    }

    return Student;
}

students *deleteStudentByOrdinalNumber(students *Student, int ordinalNumber) {
    students *p = Student;

    if(ordinalNumber == 1) {
        students *temp = Student;
        Student = Student->next;
        delete temp;
        return Student;
    }

    for(int i = 0; i < ordinalNumber - 2; i++) {
        p = p->next;
    }
    students *temp = p->next;
    p->next = p->next->next;
    delete temp;
    return Student;
}


students *addAt(students *student, int k, string name, string Class, string studentCode ) {
    students *p = student;
    for(int i = 0; i < k - 2; i++) {
        p = p->next;
    }
    students *temp = new students;
    temp->name = name;
    temp->Class = Class;
    temp->studentCode = studentCode;
    temp->next = p->next;
    p->next = temp;

    return student;
}

int main() {
    string Class;
    string name;
    string studentCode;
    students *head = NULL;
    students *tail = NULL;
    int choice;
    while (true) {
        cout << "------------------------" << endl;
        cout << "Chon lua chon cua ban: \n 1 - Them hoc sinh; \n 2 - Sua hoc sinh; \n 3 - Xoa hoc sinh; \n 4 - Hien thi hoc sinh;\n 5 - Chen hoc sinh moi vao vi tri. \n Lua chon cua ban: " ;
        cin >> choice;
        cout << "------------------------" << endl;

        if (choice == 1) {
            cout << "Nhap thong tin hoc sinh: \n - Nhap lop: ";
            cin >> Class;
            cout << "Nhap ten hoc sinh: ";
            cin.ignore();
            getline(cin, name);
            cout << "nhap ma so hoc sinh: ";

            cin >> studentCode;

            if (head == NULL) {
                head = createStudents(Class, name, studentCode);
                tail = head;
            } else {
                head = addStudents(head, Class, name, studentCode);
            }
            cout << "Sinh vien da duoc them." << endl;
            continue;
        } else if (choice == 2) {
            cout << "Chon cach sua hoc sinh: " << endl;
            cout << "Sua hoc sinh theo ma so hoc sinh - 1." << endl;
            cout << "Sua hoc sinh theo so thu tu - 2." << endl;
            cout << "Lua chon cua ban: ";
            cin >> choice;
            if (choice == 1) {
                string studentCode1;
                string studentCode2;
                cout << "Nhap ma so hoc sinh can sua: ";
                cin >> studentCode1;

                bool found = false;
                students *temp = head;
                while (temp != NULL) {
                    if (temp->studentCode == studentCode1) {
                        found = true;
                        break;
                    }
                    temp = temp->next;
                }

                if (!found) {
                    cout << "Khong tim thay hoc sinh can sua, vui long kiem tra lai ma so sinh vien." << endl;
                    continue;
                }

                cout << "Nhap lop hoc sinh moi: ";
                cin >> Class;
                cout << "Nhap ten hoc sinh moi: ";
                cin.ignore();
                getline(cin, name);
                cout << "Nhap ma so hoc sinh moi: ";
                cin >> studentCode2;

                updateStudentByName(head, studentCode1, Class, name, studentCode2);
                cout << "Sinh vien da duoc sua." << endl;
                continue;
            } else if (choice == 2) {
               int ordinalNumber;
               cout << "Nhap so thu tu hoc sinh can sua: ";
               cin >> ordinalNumber;

                cout << "Nhap lop hoc sinh moi: ";
                cin >> Class;
                cout << "Nhap ten hoc sinh moi: ";
                cin.ignore();
                getline(cin, name);
                cout << "Nhap ma so hoc sinh moi: ";
                cin >> studentCode;

                updateStudentByOrdinalNumber(head, studentCode, Class, name, ordinalNumber);
                cout << "Sinh vien da duoc sua." << endl;
                continue;
            }
        }
        else if (choice == 3) {
            cout << "Nhap cach xoa hoc sinh: " << endl;
            cout << "Xoa hoc sinh theo ma so - 1" << endl;
            cout << "Xoa hoc sinh theo so thu tu - 2 " << endl;
            cout << "Nhap cach xoa hoc sinh: " << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Nhap ma so hoc sinh can xoa " << endl;
                string studentCodeToDelete;
                cin >> studentCodeToDelete;
                head = deleteStudentByCode(head, studentCodeToDelete);
                cout << "Hoc sinh da duoc xoa." << endl;
                continue;
            } else if (choice == 2) {
                    cout << "Nhap so thu tu hoc sinh can xoa: ";
                    int num;
                    cin >> num;
                    head = deleteStudentByOrdinalNumber(head, num);
                    cout << "Hoc sinh da duoc xoa." << endl;
                    continue;
                } else {
                    cout << "Loi ! Cu phap nhap khong dung !" << endl;
                    continue;
                }
            } else if (choice == 4) {
                printStudent(head);
                continue;
            } else if (choice == 5) {
            cout << "Nhap so thu tu vi tri chen: ";
            int k;
            cin >> k;
            cout << "Nhap ten hoc sinh: ";
            string name;
            cin >> name;
            cout << "Nhap lop hoc sinh: ";
            string Class;
            cin >> Class;
            cout << "Nhap ma so hoc sinh: ";
            string studentCode;
            cin >> studentCode;
            head = addAt(head, k, name, Class, studentCode);
            cout << "Chen hoc sinh vao danh sach thanh cong." << endl;
            continue;
         } else {
                cout << "Vui long nhap dung so !" << endl;
                continue;
            }
        }
}

















    /*
     node *addAt(node *l, int k, int x){
	node *p = l;
	for (int i = 0; i < k-1; i++){
		p = p->next;
	}
	//
	node *temp = new node;
	temp->data = x;
	temp->next = p->next;
	p->next = temp;

	return l;
}*/
