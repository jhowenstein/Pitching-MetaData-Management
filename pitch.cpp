#include "pitch.h"


Pitch::Pitch(int num, float v, bool S) {
	pitch_number = num; velocity = v; strike = S;
}
int Pitch::getPitch_Number() const {
	return pitch_number;
}
float Pitch::getVelocity() const {
	return velocity;
}
bool Pitch::isStrike() const {
	return strike;
}
void Pitch::changeNumber(int newNumber) {
	pitch_number = newNumber;
}
void Pitch::change_velocity(float newV) {
	velocity = newV;
}
void Pitch::editStrike(bool newS) {
	strike = newS;
}