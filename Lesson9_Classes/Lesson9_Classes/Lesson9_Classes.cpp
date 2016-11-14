#include <iostream>
#include <string.h>

using namespace std;

class Enemy
{
public:
	Enemy(int hps, int sco);
	~Enemy();
	int get_hit_points() const;
	int get_score() const;
	void set_hit_points(int new_hit_points);
	void set_score(int new_score);
private:
	int hit_points;
	int* score;
};



Enemy::Enemy(int hps, int sco) :
	hit_points(hps)
{
	score = new int(sco);
}

Enemy::~Enemy()
{
	delete score;
}

int Enemy::get_hit_points() const
{
	return hit_points;
}

int Enemy::get_score() const
{
	return *score;
}

void Enemy::set_hit_points(const int new_hit_points)
{
	hit_points = new_hit_points;
}

void Enemy::set_score(const int new_score)
{
	*score = new_score;
}

class Player
{
public:
	Player(int hps, int sco, string nam);
	~Player();
	int get_hit_points() const;
	int get_score() const;
	string get_name() const;
	void set_hit_points(int new_hit_points);
	void set_score(int new_score);
	void set_name(string new_name);
private:
	int hit_points;
	int* score;
	string* name;
};

Player::Player(int hps, int sco, string nam):
	hit_points(hps)
{
	score = new int(sco);
	name = new string(nam);
}

Player::~Player()
{
	delete score;
	delete name;
}

int Player::get_hit_points() const
{
	return hit_points;
}

int Player::get_score() const
{
	return *score;
}

string Player::get_name() const
{
	return *name;
}

void Player::set_hit_points(const int new_hit_points)
{
	hit_points = new_hit_points;
}

void Player::set_score(const int new_score)
{
	*score = new_score;
}

void Player::set_name(const string new_name)
{
	*name = new_name;
}

int main(void)
{

	Enemy e1(2,5);
	cout << "hit points = " << e1.get_hit_points() << "\n";
	cout << "score = " << e1.get_score() << "\n";

	Enemy* e2 = new Enemy(2,4);
	e2->set_hit_points(3);
	cout << "hit points = " << e2->get_hit_points() << "\n";

	e2->set_score(2);
	cout << "score = " << e2->get_score() << "\n";

	Player p1(2, 3, "Chen Mo");

	delete e2;
	e2 = NULL;

	return 0;
}


