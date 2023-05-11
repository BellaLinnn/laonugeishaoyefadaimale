//// 能够记录多名同学的成绩
//// 并且，可以单独提出某一个人的信息进行修改
//// 注：只可以改名字，grade还有年龄。 不可以改成绩
//// 对所有同学通过成绩进行排名
//// 五个排名
// 
//// add，sub, mul, div, final
//// !!!check 看是否正确!!!
//// exam 考试 *这个不用记入排名

#include <iostream>
#include <string>
#define MAX 10//this is the maximum of students that can be added in, can change here if needed
#include <ctime>

using namespace std;

struct student {

	string s_name;
	int s_grade;
	int s_age;
	int addScore;
	int subScore;
	int mulScore;
	int divScore;
	int finalScore;
};

struct Addressbooks {
	struct student studentArray[MAX];//maximum of students can be added in, can change the maximum # at line 13

	int s_size;//to follow and record the number of students that already added in to the system
};

void showMenu();
void enterInfo(Addressbooks* abs);
void addMode(Addressbooks* abs);
//int isCorrect(int ans, int tans);
int isExist(Addressbooks* abs, string name);
void showStatsOne(Addressbooks* abs);
void showStatsAll(Addressbooks* abs);
void swap(int& a, int& b);
void showRank(Addressbooks* abs);
void editStudent(Addressbooks* abs);
void removeStudent(Addressbooks* abs);
void removeAll(Addressbooks* abs);


int main() {

	Addressbooks abs;
	abs.s_size = 0;//to make sure the size is 0 at first
	srand((unsigned int)time(NULL));

	//int select = 0;

	cout << "\nu need to input ur info to start the practice game" << endl;


	while (true) {

		int select = 0;

		showMenu();//select from menu

		cout << "\nselect one from menu" << endl;
		cin >> select;

		switch (select) {
		case 1:
			enterInfo(&abs);//let student enter their info first
			break;
		case 2://practice: select game mode(+-*/)
			//chooseGameMode(&abs);
		{
			int chs = 0;

			//system("pause");
			//system("CLS");

			cout << "\npls choose ur game mode" << endl;
			cout << "1. addition\n" << "2. substraction\n" << "3. multiplication\n" << "4. division\n" << endl;
			cin >> chs;

			while (true) {
				switch (chs) {
				case 1:
					addMode(&abs);
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				default:
					cout << "chooose one from menu pls" << endl;
				}
			}
		}
		break;
		case 3://show stats(one specific student)
			showStatsOne(&abs);
			break;
		case 4://show stats(all students)
			showStatsAll(&abs);
			break;
		case 5://show rank(5 types of ranking: + - * / and final score)
			showRank(&abs);
			break;
		case 6://edit info(change the name, grade and age only, cannot change the score
			editStudent(&abs);
			break;
		case 7://remove one specific student
			removeStudent(&abs);
			break;
		case 8://remove all students
			removeAll(&abs);
			break;
		case 0://quit
			cout << "ty 4 using" << endl;
			return 0;//return a 0 to end the program
			break;
		default://if they input a # that didnt show on menu
			cout << "u have 2 choose one from menu" << endl;
		}
	}
	return 0;
}

void enterInfo(Addressbooks* abs) {//to record every students' info


	if (abs->s_size == MAX) {//see if reached the maximum
		cout << "\nu cannot addin more student bc u reached the maximum" << endl;
		return;
	}
	else {//if not reach the maximum, students can starts to input their info here
		string name;
		int grade = 0;
		int age = 0;
		int adds = 0;

		cout << "\ninput ur name" << endl;
		cin >> name;
		abs->studentArray[abs->s_size].s_name = name;//use pointer to save it into the struct

		cout << "input ur grade" << endl;
		cin >> grade;
		abs->studentArray[abs->s_size].s_grade = grade;//use pointer to save it into the struct

		cout << "input ur age" << endl;
		cin >> age;
		abs->studentArray[abs->s_size].s_age = age;//use pointer to save it into the struct


		cout << "input add score" << endl;
		cin >> adds;
		abs->studentArray[abs->s_size].addScore = adds;//use pointer to save it into the struct


		abs->s_size++;//add 1 every time it repeats, to show that theres 1 student more

		cout << "\nAdded successfully" << endl;//a reminder
	}

	//system("pause");
	//system("CLS");//clear screen
}

void showMenu() {
	cout << "\n1. Input info" << endl;
	cout << "2. Start practice" << endl;
	cout << "3. show stats one" << endl;
	cout << "4. show all stats" << endl;
	cout << "5. show rank" << endl;
	cout << "6. edit info" << endl;
	cout << "7. remove one student" << endl;
	cout << "8. remove all" << endl;
	cout << "0. quit" << endl;
}

//void chooseGameMode(Addressbooks *abs) {
//
//	int chs = 0;
//	cout << "pls choose ur game mode" << endl;
//	cout << "addition\n" << "substraction\n" << "multiplication\n" << "division\n" << endl;
//
//	while (true) {
//		switch (chs) {
//		case 1:
//			addMode(&abs);
//			break;
//		case 2:
//			break;
//		case 3:
//			break;
//		case 4:
//			break;
//		default:
//			cout << "chooose one from menu pls" << endl;
//			return;
//		}
//	}
//}

void addMode(Addressbooks* abs) {

	int num1 = rand() % 10 + 1;
	int num2 = rand() % 10 + 1;

	int ans = 0;
	int tans = num1 + num2;
	int tries = 1;

	cout << "\n" << num1 << " + " << num2 << "\n= " << endl;
	cin >> ans;

	while ((tans != ans) && (tries <= 2)) {
		cout << "wrong answer, u have " << 2 - tries << " more tries" << endl;
		tries++;
		cin >> ans;
		break;
	}

	if (ans == tans) {
		cout << "congrats! u got it right!" << endl;
		abs->studentArray[abs->s_size].addScore++;
		//return;
	}
	//break;
	//return;
	//exit();
}

//void addMode(Addressbooks *abs) {
//	
//	for (int j = 1; j < 6;) {
//
//		int num1 = rand() % 100 + 1;
//		int num2 = rand() % 100 + 1;
//
//		int a = 0;
//		int tans = num1 + num2;
//
//		cout << "\nur now in add mode\n"
//			 << "u have 3 tries total for each questions\n"
//			 << "u will not recive credit for that question if u got that wrong for 3 times" << endl;
//
//		cout << "\n" << j << ". " << num1 << " + " << num2 << " \n  = " << endl;
//
//		for (int i = 0; i < 3; i++) {
//
//			cin >> a;
//
//			if (a == tans) {
//				cout << "congrats! u got it right!" << endl;
//				//abs->studentArray[abs->s_size].addScore++;
//				//return 1;
//				abs->studentArray[abs->s_size].addScore++;
//				//i++;
//				//j++;
//				//system("pause");
//				//system("CLS");
//				return;
//			}
//			else if (i < 2 && a != tans) {
//				cout << "wrong answer, u have " << 2 - i << " more tries" << endl;
//			}
//			else {
//				cout << "sry ur wrong for 3 times" << endl;
//				//return -1;
//				//system("pause");
//				//system("CLS");
//				//j++;
//				//return;
//			}
//		}
//	}
//	//int pts = isCorrect(ans,tans);
//	//if (pts != -1) {
//	//	abs->studentArray[abs->s_size].addScore++;
//	//	system("pause");
//	//	system("CLS");
//	//}
//	//else {
//	//	system("pause");
//	//}
//	//system("pause");
//	//system("CLS");
//}

//int isCorrect(int ans, int tans) {
//
//	for (int i = 0; i > 3; i++) {
//
//		if (ans == tans) {
//			cout << "congrats! u got it right!" << endl;
//			//abs->studentArray[abs->s_size].addScore++;
//			return 1;
//		}
//		else if (i == 3 && ans != tans) {
//			cout << "this is ur last try!" << endl;
//		}
//		else if (i < 3 && ans != tans) {
//			cout << "wrong answer, u have " << 3 - i << " more tries" << endl;
//		}
//		else {
//			cout << "sry ur wrong for 3 times" << endl;
//			return -1;
//		}
//	}
//}

void showStatsAll(Addressbooks* abs) {
	if (abs->s_size == 0) {
		cout << "add a student before show stats" << endl;
	}
	else {
		for (int i = 0; i < abs->s_size; i++) {
			cout << "\n" << i + 1 << ". " << endl;
			cout << "name: " << abs->studentArray[i].s_name
				<< "\tgrade: " << abs->studentArray[i].s_grade
				<< "\tage: " << abs->studentArray[i].s_age
				<< "\tadd socre: " << abs->studentArray[i].addScore
				<< "\tsub score: " << abs->studentArray[i].subScore
				<< "\nmul score: " << abs->studentArray[i].mulScore
				<< "\ndiv score: " << abs->studentArray[i].divScore << endl;
		}
	}
}

int isExist(Addressbooks* abs, string name) {

	for (int i = 0; i < abs->s_size; i++) {

		if (abs->studentArray[i].s_name == name) {
			return i;
		}
	}
	return -1;
}

void showStatsOne(Addressbooks* abs) {
	string name;

	cout << "Input the name of person u wanna search" << endl;
	cin >> name;

	int ret = isExist(abs, name);//y its not &abs

	if (ret != -1) {//founded

		cout << "name: " << abs->studentArray[ret].s_name
			 << "\tphone: " << abs->studentArray[ret].s_grade
			 << "\tage: " << abs->studentArray[ret].s_age
			 << "\tadd socre: " << abs->studentArray[ret].addScore
			 << "\tsub score: " << abs->studentArray[ret].subScore
			 << "\nmul score: " << abs->studentArray[ret].mulScore
			 << "\ndiv score: " << abs->studentArray[ret].divScore << endl;
	}
	else {//not founded

		cout << "u never add this person in" << endl;
	}

}

void editStudent(Addressbooks* abs) {
	string name;

	cout << "Input the name of person u wanna edit info" << endl;
	cin >> name;

	int ret = isExist(abs, name);//y its not &abs

	if (ret != -1) {//founded
				//name
		cout << "Input name" << endl;
		cin >> name;
		abs->studentArray[ret].s_name = name;

		int grade = 0;
		cout << "input grade" << endl;
		cin >> grade;
		abs->studentArray[ret].s_grade = grade;

		int age = 0;
		cout << "input age" << endl;
		cin >> age;
		abs->studentArray[ret].s_age = age;


		cout << "edited student info successfully" << endl;
	}
	else {//not founded

		cout << "u never add this person in" << endl;
	}
}

void removeStudent(Addressbooks* abs) {

	string name;

	cout << "Input the name of person u wanna remove" << endl;
	cin >> name;

	int ret = isExist(abs, name);//y its not &abs

	if (ret != -1) {//founded

		for (int i = ret; i < abs->s_size; i++) {

			abs->studentArray[i] = abs->studentArray[i + 1];
		}

		abs->s_size--;
		cout << "u removed this person successfully" << endl;
	}
	else {//not founded

		cout << "u never add this person in" << endl;
	}

}

void removeAll(Addressbooks* abs) {

	abs->s_size = 0;
	cout << "your contact list are already cleared" << endl;
}

void showRank(Addressbooks* abs) {
	int max;
	int index;
	//int SIZE = sizeof(abs->studentArray) / sizeof(abs->studentArray[0]);

	for (max = abs -> s_size - 1; max > 0; max--) {

		for (index = 0; index < max; index++) {

			if (abs->studentArray[index].addScore > abs->studentArray[index + 1].addScore) {

				swap(abs->studentArray[index].addScore, abs->studentArray[index + 1].addScore);
			}
		}
	}

	for (int i = abs->s_size - 1; i >= 0; i--) {
		cout << "\n" << abs->studentArray[i].addScore << endl;
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}