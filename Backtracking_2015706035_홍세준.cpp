#include <iostream>

using namespace std;

#define First 1
#define Second 2
#define Third 3
#define Forth 4
#define Fifth 5

#define Blue 1
#define Green 2
#define Red 3
#define White 4
#define Yellow 5

#define Brit 1
#define Dane 2
#define German 3
#define Norwegian 4
#define Swede 5

#define Beer 1
#define Coffee 2
#define Milk 3
#define Tea 4
#define Water 5

#define BlueMaster 1
#define Dunhill 2
#define PallMall 3
#define Prince 4
#define Blend 5

#define Cat 1
#define Bird 2
#define Dog 3
#define Fish 4
#define Horse 5

struct HOUSE {
	int LOCATE;
	int COLOR;
	int NATION;
	int BEVERAGE;
	int CIGAR;
	int PET;
};

HOUSE house[5];

void result(int node) {
	cout << endl;
	for (int i = 0; i < 5; i++) {
		if (house[i].PET == 0) {
			house[i].PET = Fish;
		}
	}
	cout << " Node : " << node << endl << endl;

	for (int i = 0; i < 5; i++) {
		cout <<" "<< i + 1 << "번째 집에 사는 사람 특징 : ";
		cout << "Color - " << house[i].COLOR;
		cout << ", Nation - "<<house[i].NATION ;
		cout << ", Beverage - "<<house[i].BEVERAGE;
		cout << ", Cigar - "<<house[i].CIGAR;
		cout << ", Pet - "<<house[i].PET;
		cout << endl;
	}
	cout << endl;
	return;
}

void Promising10(int node) {
	for (int i = 0; i < 5; i++) {
		node++;
		if (house[i].CIGAR == Blend) {
			if (house[i].LOCATE == First) {
				node++;
				if (house[i + 1].LOCATE == Second && house[i + 1].PET == 0) {
					house[i + 1].PET = Cat;
					result(node);
					house[i + 1].PET = 0;
				}
			}

			else if (house[i].LOCATE == Fifth) {
				node++;
				if (house[i - 1].LOCATE == Forth && house[i - 1].CIGAR == 0) {
					house[i - 1].PET = Cat;
					result(node);
					house[i - 1].PET = 0;
				}
			}

			else {
				int temp = house[i].LOCATE;
				node++;
				if (house[i - 1].LOCATE == temp - 1 && house[i - 1].PET == 0) {
					house[i - 1].PET = Cat;
					result(node);
					house[i - 1].PET = 0;
				}

				else if (house[i + 1].LOCATE == temp + 1 && house[i + 1].PET == 0) {
					house[i + 1].PET = Cat;
					result(node);
					house[i + 1].PET = 0;
				}

			}
		}
	}
}

void Promising6(int node) {
	for (int i = 0; i < 5; i++) {
		node += 1;
		if (house[i].CIGAR == 0 && house[i].PET == 0) {
			house[i].CIGAR = PallMall;
			house[i].PET = Bird;
			Promising10(node);
			house[i].CIGAR = 0;
			house[i].PET = 0;
			node += 1;
		}
	}
}

void Promising2(int node) {
	for (int i = 0; i < 5; i++) {
		node += 1;
		if (house[i].NATION == 0 && house[i].PET == 0) {
			house[i].NATION = Swede;
			house[i].PET = Dog;
			Promising6(node);
			house[i].NATION = 0;
			house[i].PET = 0;
			node += 1;
		}
	}
}

void Promising13(int node) {
	for (int i = 0; i < 5; i++) {
		node += 1;
		if (house[i].NATION == 0 && house[i].CIGAR == 0) {
			house[i].NATION = German;
			house[i].CIGAR = Prince;
			Promising2(node);
			house[i].NATION = 0;
			house[i].CIGAR = 0;
			node += 1;
		}
	}
}

void Promising15(int node) {
	for (int i = 0; i < 5; i++) {
		node++;
		if (house[i].CIGAR == 0) {
			if (house[i].LOCATE == First) {
				node++;
				if (house[i + 1].LOCATE == Second && house[i + 1].BEVERAGE == 0) {
					house[i + 1].BEVERAGE = Water;
					house[i].CIGAR = Blend;
					Promising13(node);
					house[i + 1].BEVERAGE = 0;
					house[i].CIGAR = 0;
				}
			}


			else if (house[i].LOCATE == Fifth) {
				node++;
				if (house[i - 1].LOCATE == Forth && house[i - 1].BEVERAGE == 0) {
					house[i - 1].BEVERAGE = Water;
					house[i].CIGAR = Blend;
					Promising13(node);
					house[i - 1].BEVERAGE = 0;
					house[i].CIGAR = 0;
				}
			}


			else {
				int temp = house[i].LOCATE;
				node++;
				if (house[i - 1].LOCATE == temp - 1 && house[i - 1].BEVERAGE == 0) {
					house[i - 1].BEVERAGE = Water;
					house[i].CIGAR = Blend;
					Promising13(node);
					house[i - 1].BEVERAGE = 0;
					house[i].CIGAR = 0;
				}

				else if (house[i + 1].LOCATE == temp + 1 && house[i + 1].BEVERAGE == 0) {
					house[i + 1].BEVERAGE = Water;
					house[i].CIGAR = Blend;
					Promising13(node);
					house[i + 1].BEVERAGE = 0;
					house[i].CIGAR = 0;
				}
			}
		}
	}
}

void Promising12(int node) {
	for (int i = 0; i < 5; i++) {
		node += 1;
		if (house[i].CIGAR == 0 && house[i].BEVERAGE == 0) {
			house[i].CIGAR = BlueMaster;
			house[i].BEVERAGE = Beer;
			Promising15(node);
			house[i].CIGAR = 0;
			house[i].BEVERAGE = 0;
			node += 1;
		}
	}
}

void Promising3(int node) {
	for (int i = 0; i < 5; i++) {
		node += 1;
		if (house[i].NATION == 0 && house[i].BEVERAGE == 0) {
			house[i].NATION = Dane;
			house[i].BEVERAGE = Tea;
			Promising12(node);
			house[i].NATION = 0;
			house[i].BEVERAGE = 0;
			node += 1;
		}
	}
}

void Promising11(int node) {
	for (int i = 0; i < 5; i++) {
		node++;
		if (house[i].CIGAR == Dunhill) {
			if (house[i].LOCATE == First) {
				node++;
				if (house[i + 1].LOCATE == Second && house[i + 1].PET == 0) {
					house[i + 1].PET = Horse;
					Promising3(node);
					house[i + 1].PET = 0;
				}
			}
			else if (house[i].LOCATE == Fifth) {
				node++;
				if (house[i - 1].LOCATE == Forth && house[i - 1].PET == 0) {
					house[i - 1].PET = Horse;
					Promising3(node);
					house[i - 1].PET = 0;
				}
			}
			else {
				int temp = house[i].LOCATE;
				node++;
				if (house[i - 1].LOCATE == temp - 1 && house[i - 1].PET == 0) {
					house[i - 1].PET = Horse;
					Promising3(node);
					house[i - 1].PET = 0;
				}
				else if (house[i + 1].LOCATE == temp + 1 && house[i + 1].PET == 0) {
					house[i + 1].PET = Horse;
					Promising3(node);
					house[i + 1].PET = 0;
				}
			}
		}
	}
}

void Promising7(int node) {
	for (int i = 0; i < 5; i++) {
		node += 1;
		if (house[i].COLOR == 0 && house[i].CIGAR == 0) {
			house[i].COLOR = Yellow;
			house[i].CIGAR = Dunhill;
			Promising11(node);
			house[i].COLOR = 0;
			house[i].CIGAR = 0;
			node += 1;
		}
	}
}

void Promising1(int node) {
	for (int i = 0; i < 5; i++) {
		node+=1;
		if (house[i].NATION == 0 && house[i].COLOR == 0) {
			house[i].NATION = Brit;
			house[i].COLOR = Red;
			Promising7(node);
			house[i].NATION = 0;
			house[i].COLOR = 0;
			node += 1;
		}
	}
}

void Promising5(int node) {
	for (int i = 0; i < 5; i++) {
		node += 1;
		if (house[i].COLOR == Green && house[i].BEVERAGE == 0) {
			
			house[i].BEVERAGE = Coffee;
			Promising1(node);
			house[i].BEVERAGE = 0;
			node += 1;
		}
	}
}

void Promising4(int node) {
	for (int i = 0; i < 5; i++) {
		node += 1;
		if (house[i].COLOR == 0 && house[i + 1].COLOR == 0) {
			house[i].COLOR = Green;
			house[i + 1].COLOR = White;
			house[i].LOCATE = i;
			house[i + 1].LOCATE = i + 1;

			Promising5(node);
			house[i].COLOR = 0;
			house[i + 1].COLOR = 0;;
			node += 1;
		}
	}
	
}

void Promising14(int node) {
	for (int i = 0; i < 5; i++) {
		node += 1;
		if (house[i].NATION == Norwegian && house[i+1].LOCATE==Second &&house[i + 1].COLOR == 0) {
			house[i + 1].COLOR = Blue;
			Promising4(node);
			house[i].NATION = 0;
			house[i+1].COLOR = 0;
			node += 1;
		}
	}
}

void Promising8(int node) {
	for (int i = 0; i < 5; i++) {
		node += 1;
		if (house[i].LOCATE == Third && house[i].BEVERAGE == 0) {
			house[i].BEVERAGE = Milk;
			Promising14(node);
			house[i].BEVERAGE = 0;
			node += 1;
		}
	}
}

void Promising9(int node) {
	for (int i = 0; i < 5; i++) {
		node += 1;
		if (house[i].NATION == 0 && house[i].LOCATE == First) {
			house[i].NATION = Norwegian;
			Promising8(node);
			house[i].NATION = 0;
			node += 1;
		}
	}
}

int main(void) {

	for (int i = 0; i < 5; i++) {
		house[i].LOCATE = 0;
		house[i].COLOR = 0;
		house[i].NATION = 0;
		house[i].BEVERAGE = 0;
		house[i].CIGAR = 0;
		house[i].PET = 0;
	}
	house[0].LOCATE = First;
	house[1].LOCATE = Second;
	house[2].LOCATE = Third;
	house[3].LOCATE = Forth;
	house[4].LOCATE = Fifth;

	int node = 1;

	Promising9(node);
	
	system("pause");
	return 0;
}