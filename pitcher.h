#include "pitch.cpp"

class Pitcher {
private: 
	int ID;
	int age;
	float height;
	float weight;
	char hand;
	Pitch* pitch_list[20];
	int pitch_count;

public:
	Pitcher(int id, int _age, float _height, float _weight, char _hand);
	int getID() const;
	int getAge() const;
	float getHeight() const;
	float getWeight() const;
	char getHand() const;
	void addPitch(int num, float v, bool S);
	void printPitch(int p);
	int numberStrikes();
	int numberBalls();
	Pitch** returnStrikes();
	Pitch** returnBalls();
	Pitch** bestStrikes();
	void printBestStrikes();
	float bestStrikes_AverageVelocity();
	float proportionStrikes();
	void PrintPerformanceSummary();
	void PrintPerformance();
};