studentNode* createStudent(char studentUser[50], char studentPassw[50]);
void makeStudentTmp(studentNode* parent, char studentUser[50], char studentPassw[50]);
void makeStudent(studentNode* head, char studentUser[50], char studentPassw[50]);
void destroyTreeStudents(studentNode *head);
void saveDataStudents(studentNode* head);
void saveOtherDataStudents();
int logInStudent(studentNode *head, char studentUser[50], char studentPassw[50], int *val);