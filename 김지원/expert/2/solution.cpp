struct Student{
    int id;
    int grade;
    char gender[7];
    int score;
};
struct FindGrade{
  char grade;
  bool operator()(student st)
  {
    return (st.grade == grade);
  }
};

vector<Student> v(20000);
Student st;
void init() {
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
    st.grade=mGrade;
    st.gender=mGender;
    st.score=mScore;
    v.push_back(st);
    FindGrade find;
    find.grade='mGrade';
    vector<Student>::iterator sameGrade;
    sameGrade = find_if(v.begin(), v.end(), find());
    cout << sameGrade[0].score;
	return 0;
}

int remove(int mId) {
	return 0;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
	return 0;
}