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
	int addScore = 0;
	int subScore = 0;
	int mulScore = 0;
	int divScore = 0;
	int finalScore = 0;
};

struct Addressbooks {
	struct student studentArray[MAX];//maximum of students can be added in, can change the maximum # at line 13

	int s_size;//to follow and record the number of students that already added in to the system
};

void showMenu();
void enterInfo(Addressbooks* abs);
void addMode(Addressbooks* abs);
void subMode(Addressbooks* abs);
void mulMode(Addressbooks* abs);
void divMode(Addressbooks* abs);
int isExist(Addressbooks* abs, string name);
void showStatsOne(Addressbooks* abs);
void showStatsAll(Addressbooks* abs);
void editStudent(Addressbooks* abs);
void removeStudent(Addressbooks* abs);
void removeAll(Addressbooks* abs);
void showAddRank(Addressbooks* abs);
void showSubRank(Addressbooks* abs);
void showMulRank(Addressbooks* abs);
void showDivRank(Addressbooks* abs);
void showFinalRank(Addressbooks* abs);
void swap(int& a, int& b);


int main() {

	Addressbooks abs;
	abs.s_size = 0;//to make sure the size is 0 at first
	srand((unsigned int)time(NULL));


	std::cout << "\nu need to input ur info to start the practice game" << endl;


	while (true) {

		int select = 0;

		showMenu();//select from menu

		std::cout << "\nselect one from menu" << endl;
		cin >> select;

		switch (select) {
		case 1:
			enterInfo(&abs);//let student enter their info first
			break;
		case 2://practice: select game mode(+-*/)
		{
			int chs = 0;


			std::cout << "\npls choose ur game mode" << endl;
			std::cout << "1. addition\n" << "2. substraction\n" << "3. multiplication\n" << "4. division\n" << endl;
			cin >> chs;

			//while (true) {
				switch (chs) {
				case 1:
					addMode(&abs);
					break;
				case 2:
					subMode(&abs);
					break;
				case 3:
					mulMode(&abs);
					break;
				case 4:
					divMode(&abs);
					break;
				default:
					std::cout << "chooose one from menu pls" << endl;
				}
			//}
		}
		break;
		case 3://show stats(one specific student)
			showStatsOne(&abs);
			break;
		case 4://show stats(all students)
			showStatsAll(&abs);
			break;
		case 5://show rank(5 types of ranking: + - * / and final score)
		{
			int haha = 0;

			cout << "What type of rank you wanna see" << endl;
			cout << "1. Add"
				<< "\n2. Sub"
				<< "\n3. Mul"
				<< "\n4. Div"
				<< "\n5. Final" << endl;
			cin >> haha;

			//if (haha == 1) {
			//	showAddRank(&abs);
			//}
			//else if (haha == 2) {
			//	showSubRank(&abs);
			//}
			//else if (haha == 3) {
			//	showMulRank(&abs);
			//}
			//else if (haha == 4) {
			//	showDivRank(&abs);
			//}
			//else if (haha == 5) {
			//	showFinalRank(&abs);
			//}
			//else {
			//	cout << "choose 1-5 pls" << endl;
			//	return;
			//}

			switch (haha) {
			case 1:
				showAddRank(&abs);
				break;
			case 2:
				showSubRank(&abs);
				break;
			case 3:
				showMulRank(&abs);
				break;
			case 4:
				showDivRank(&abs);
				break;
			case 5:
				showFinalRank(&abs);
				break;
			default:
				std::cout << "chooose one from menu pls" << endl;
			}

		}
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
			std::cout << "ty 4 using" << endl;
			return 0;//return a 0 to end the program
			break;
		default://if they input a # that didnt show on menu
			std::cout << "u have 2 choose one from menu" << endl;
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
		abs->studentArray[abs->s_size + 1].s_name = name;//use pointer to save it into the struct

		cout << "input ur grade" << endl;
		cin >> grade;
		abs->studentArray[abs->s_size + 1].s_grade = grade;//use pointer to save it into the struct

		cout << "input ur age" << endl;
		cin >> age;
		abs->studentArray[abs->s_size + 1].s_age = age;//use pointer to save it into the struct


		abs->s_size++;//add 1 every time it repeats, to show that theres 1 student more

		std::cout << "\nAdded successfully" << endl;//a reminder
	}
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
		abs->studentArray[abs->s_size].addScore++;
		abs->studentArray[abs->s_size].finalScore++;
		cout << "congrats! u got it right!" << endl;
	}
}

void subMode(Addressbooks* abs) {

	int num1 = rand() % 10 + 1;
	int num2 = rand() % 10 + 1;

	int ans = 0;
	int tans = num1 - num2;
	int tries = 1;

		cout << "\n" << num1 << " - " << num2 << "\n= " << endl;
		cin >> ans;

	while ((tans != ans) && (tries <= 2)) {
		cout << "wrong answer, u have " << 2 - tries << " more tries" << endl;
		tries++;
		cin >> ans;
		break;
	}

	if (ans == tans) {
		abs->studentArray[abs->s_size].subScore++;
		abs->studentArray[abs->s_size].finalScore++;
		cout << "congrats! u got it right!" << endl;
	}
}

void mulMode(Addressbooks* abs) {

	int num1 = rand() % 10 + 1;
	int num2 = rand() % 10 + 1;

	int ans = 0;
	int tans = num1 * num2;
	int tries = 1;

		cout << "\n" << num1 << " * " << num2 << "\n= " << endl;
		cin >> ans;

	while ((tans != ans) && (tries <= 2)) {
		cout << "wrong answer, u have " << 2 - tries << " more tries" << endl;
		tries++;
		cin >> ans;
		break;
	}

	if (ans == tans) {
		abs->studentArray[abs->s_size].mulScore++;
		abs->studentArray[abs->s_size].finalScore++;
		cout << "congrats! u got it right!" << endl;
	}
}

void divMode(Addressbooks* abs) {


	int num1 = rand() % 99 + 10;
	int num2 = rand() % 9 + 1;

	int ans = 0;
	int tans = num1 / num2;
	int tries = 1;
	int gun = num1 % num2;

	num1 = num1 - gun;

		cout << "\n" << num1 << " / " << num2 << "\n= " << endl;
		cin >> ans;

		while ((tans != ans) && (tries <= 2)) {
			cout << "wrong answer, u have " << 2 - tries << " more tries" << endl;
			tries++;
			cin >> ans;
			break;
		}

		if (ans == tans) {
			abs->studentArray[abs->s_size].divScore++;
			abs->studentArray[abs->s_size].finalScore++;
			cout << "congrats! u got it right!" << endl;
		}
}

void showStatsAll(Addressbooks* abs) {
	if (abs->s_size == 0) {
		cout << "add a student before show stats" << endl;
	}
	else {
		for (int i = 0; i <= abs->s_size; i++) {
			if (i == 0) {
				i++;
			}
			cout << "\n" << i << ". " << endl;
			cout << "name: " << abs->studentArray[i].s_name
				 << "\ngrade: " << abs->studentArray[i].s_grade
				 << "\nage: " << abs->studentArray[i].s_age
				 << "\nadd socre: " << abs->studentArray[i].addScore
				 << "\nsub score: " << abs->studentArray[i].subScore
				 << "\nmul score: " << abs->studentArray[i].mulScore
				 << "\ndiv score: " << abs->studentArray[i].divScore 
				 << "\nfinal score: " << abs->studentArray[i].finalScore << endl;
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
			 << "\nphone: " << abs->studentArray[ret].s_grade
			 << "\nage: " << abs->studentArray[ret].s_age
			 << "\nadd socre: " << abs->studentArray[ret].addScore
			 << "\nsub score: " << abs->studentArray[ret].subScore
			 << "\nmul score: " << abs->studentArray[ret].mulScore
			 << "\ndiv score: " << abs->studentArray[ret].divScore
			 << "\nfinal score: " << abs->studentArray[ret].finalScore << endl;
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
	return;
}

void showAddRank(Addressbooks* abs) {
	int max;
	int index;

	for (max = abs -> s_size - 1; max > 0; max--) {

		for (index = 0; index < max; index++) {

			if (abs->studentArray[index].addScore > abs->studentArray[index + 1].addScore) {

				swap(abs->studentArray[index].addScore, abs->studentArray[index + 1].addScore);
			}
		}
	}

	for (int i = abs->s_size; i > 0; i--) {

		cout << "\n" << abs->studentArray[i].s_name << "---" << abs->studentArray[i].addScore << endl;
	}
}

void showSubRank(Addressbooks* abs) {
	int max;
	int index;

	for (max = abs->s_size - 1; max > 0; max--) {

		for (index = 0; index < max; index++) {

			if (abs->studentArray[index].subScore > abs->studentArray[index + 1].subScore) {

				swap(abs->studentArray[index].subScore, abs->studentArray[index + 1].subScore);
			}
		}
	}

	for (int i = abs->s_size; i > 0; i--) {

		cout << "\n" << abs->studentArray[i].s_name << "---" << abs->studentArray[i].subScore << endl;
	}
}

void showMulRank(Addressbooks* abs) {
	int max;
	int index;

	for (max = abs->s_size - 1; max > 0; max--) {

		for (index = 0; index < max; index++) {

			if (abs->studentArray[index].mulScore > abs->studentArray[index + 1].mulScore) {

				swap(abs->studentArray[index].mulScore, abs->studentArray[index + 1].mulScore);
			}
		}
	}

	for (int i = abs->s_size; i > 0; i--) {

		cout << "\n" << abs->studentArray[i].s_name << "---" << abs->studentArray[i].mulScore << endl;
	}
}

void showDivRank(Addressbooks* abs) {
	int max;
	int index;

	for (max = abs->s_size - 1; max > 0; max--) {

		for (index = 0; index < max; index++) {

			if (abs->studentArray[index].divScore > abs->studentArray[index + 1].divScore) {

				swap(abs->studentArray[index].divScore, abs->studentArray[index + 1].divScore);
			}
		}
	}

	for (int i = abs->s_size; i > 0; i--) {

		cout << "\n" << abs->studentArray[i].s_name << "---" << abs->studentArray[i].divScore << endl;
	}
}

void showFinalRank(Addressbooks* abs) {
	int max;
	int index;

	for (max = abs->s_size - 1; max > 0; max--) {

		for (index = 0; index < max; index++) {

			if (abs->studentArray[index].finalScore > abs->studentArray[index + 1].finalScore) {

				swap(abs->studentArray[index].finalScore, abs->studentArray[index + 1].finalScore);
			}
		}
	}

	for (int i = abs->s_size; i > 0; i--) {

		cout << "\n" << abs->studentArray[i].s_name << "---" << abs->studentArray[i].finalScore << endl;
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}