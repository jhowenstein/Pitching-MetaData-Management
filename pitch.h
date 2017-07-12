

class Pitch {
private:
	int pitch_number;
	float velocity;
	bool strike;

public:
	Pitch(int num, float v, bool S);
	int getPitch_Number() const;
	float getVelocity() const;
	bool isStrike() const;
	void changeNumber(int newNumber);
	void change_velocity(float newV);
	void editStrike(bool newS);
};