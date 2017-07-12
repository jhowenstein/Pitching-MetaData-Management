#include "pitcher.h"


Pitcher::Pitcher(int id, int _age, float _height, float _weight, char _hand) {
	ID = id; age = _age; height = (_height/100.0); weight = (_weight/2.20462); hand = _hand; pitch_count = 0;
}
int Pitcher::getID() const {
	return ID;
}
int Pitcher::getAge() const {
	return age;
}
float Pitcher::getHeight() const {
	return height;
}
float Pitcher::getWeight() const {
	return weight;
}
char Pitcher::getHand() const {
	return hand;
}
void Pitcher::addPitch(int num, float v, bool S) {
	pitch_list[pitch_count] = new Pitch( num, v, S );
	pitch_count++;
}
void Pitcher::printPitch(int p) {
	if (p > pitch_count) {
		cout << "Error. Pitch not found." << endl;
		return;
	}
	p = p - 1;
	cout << "Pitch Number: " << pitch_list[p]->getPitch_Number() << ", " << "Velocity: " << pitch_list[p]->getVelocity() << ", " << "Strike?: " << pitch_list[p]->isStrike() << endl;
}
int Pitcher::numberStrikes() {
	int numStrikes = 0;
	for (int i = 0; i < pitch_count; i++) {
		numStrikes += pitch_list[i]->isStrike();
	}
	return numStrikes;
}
int Pitcher::numberBalls() {
	return (pitch_count - numberStrikes());
}
Pitch** Pitcher::returnStrikes() {
	int n = numberStrikes();
	Pitch** strikes;
	strikes = new Pitch*[n];
	int k = 0;
	for (int i = 0; i < pitch_count; i++) {
		if (pitch_list[i]->isStrike()) {
			strikes[k] = pitch_list[i];
			k++;
		}
	}
	return strikes;
}

Pitch** Pitcher::returnBalls() {
	int n = numberBalls();
	Pitch** balls = new Pitch* [n];
	int k = 0;
	for (int i = 0; i < pitch_count; i++) {
		if (!pitch_list[i]->isStrike()) {
			balls[k] = pitch_list[i];
			k++;
		}
	}
	return balls;
}

// Returns the 5 fastest strikes thrown by the pitcher
Pitch** Pitcher::bestStrikes() {
	int n = numberStrikes();
	Pitch** strikes = returnStrikes();
	Pitch** bestFive = new Pitch* [5];
	for (int i = 0; i < 5; i++) {
		bestFive[i] = NULL;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			if (bestFive[j] == NULL) {
				bestFive[j] = strikes[i];
				break;
			}
			else if (strikes[i]->getVelocity() > bestFive[j]->getVelocity()) {
				for (int ii = 4; ii > j; ii--) {
					bestFive[ii] = bestFive[ii - 1];
				}
				bestFive[j] = strikes[i];
				break;
			}
		}
	}
	return bestFive;
}
void Pitcher::printBestStrikes() {
	Pitch** bestFive = bestStrikes();
	for (int i = 0; i < 5; i++) {
		cout << "Pitch Number: " << bestFive[i]->getPitch_Number() << ", " << "Pitch Velocity: " << bestFive[i]->getVelocity() << endl;
	}
}
float Pitcher::bestStrikes_AverageVelocity() {
	Pitch** bestFive = bestStrikes();
	float total_v = 0;
	for (int i = 0; i < 5; i++) {
		total_v += bestFive[i]->getVelocity();
	}
	float avg_V = total_v/5.0;
	return avg_V;
}
float Pitcher::proportionStrikes() {
	int S = numberStrikes();
	int B = numberBalls();
	float p = (float)S/((float)S + (float)B);
	return p;
}
void Pitcher::PrintPerformanceSummary() {
	cout << "\n";
	cout << "Athlete ID: " << getID() << endl;
	cout << "Athlete Age: " << getAge() << endl;
	cout << "Athlete Height: " << getHeight() << endl;
	cout << "Athlete Weight: " << getWeight() << endl;
	cout << "Number Strikes: " << numberStrikes() << endl;
	cout << "Number Balls: " << numberBalls() << endl;
	cout << "Strike Proportion: " << proportionStrikes() << endl;
	cout << "Best Strikes Thrown:\n";
	printBestStrikes();
	cout << "Best Strikes Average Velocity: " << bestStrikes_AverageVelocity() << endl;
}
void Pitcher::PrintPerformance() {
	cout << "\n";
	cout << "Athlete ID: " << getID() << endl;
	cout << "Athlete Age: " << getAge() << endl;
	cout << "Athlete Height: " << getHeight() << endl;
	cout << "Athlete Weight: " << getWeight() << endl;
	cout << "Number Strikes: " << numberStrikes() << endl;
	cout << "Number Balls: " << numberBalls() << endl;
	cout << "Strike Proportion: " << proportionStrikes() << endl;
	cout << "All Pitches:\n";
	for (int i = 1; i <= pitch_count; i++) {
		printPitch(i);
	}
}