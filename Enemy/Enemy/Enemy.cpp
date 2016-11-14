#include <iostream>
#include <vector>
#include <stack>   
#include <queue> 

using namespace std;

// declare enemy class

class Enemy
{
public:
	Enemy(int hps);
	Enemy();
	virtual ~Enemy();
	virtual int get_hit_points() const;
	virtual int get_score() const;
	virtual void set_hit_points(int new_hit_points);
	virtual	void set_score(int new_score);
protected:
	int hit_points;
	int* score;
};

// define enemy class

Enemy::Enemy(int hps) :
	hit_points(hps)
{
	score = new int(1);
}

Enemy::Enemy()
{
	hit_points = 2;
	score = new int(1);
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

// declare flying enemy class

class ArmedEnemy : public Enemy
{
public:
	ArmedEnemy(int hps, int ammo);
	ArmedEnemy();
	virtual ~ArmedEnemy();
	virtual void set_score(int new_score);
	virtual void shoot();
	friend ostream& operator<<(ostream& ostr, const ArmedEnemy arm_e);
protected:
	int ammo_level;
};

// define flying enemy class

ArmedEnemy::ArmedEnemy(int hps, int ammo) :
	Enemy(hps),
	ammo_level(ammo)
{
}

ArmedEnemy::ArmedEnemy() :Enemy(2)
{
	ammo_level = 3;
}

ArmedEnemy::~ArmedEnemy()
{
}

void ArmedEnemy::set_score(const int new_score)
{
	*score = new_score;
	cout << "score is now " << *score << "\n";
}

void ArmedEnemy::shoot()
{
	if (ammo_level > 0)
	{
		cout << "bang!\n";
		--ammo_level;
	}
	else
	{
		cout << "out of ammo\n";
	}
}

ostream& operator<<(ostream& ostr, const ArmedEnemy arm_e)
{
	ostr << "this ArmedEnemy have " << arm_e.get_hit_points() << " hit points" << "\n";
	ostr << "this ArmedEnemy have " << arm_e.get_score() << " scores" << "\n";
	return ostr;
}

int main(void)
{
	vector<ArmedEnemy> v_ar(1);
	stack<ArmedEnemy> s_ar;
	queue<ArmedEnemy> q_ar;
	stack<ArmedEnemy> s_ar_a;



	ArmedEnemy ar_a(5, 5);
	ArmedEnemy ar_b(5, 4);
	ArmedEnemy ar_c(4, 5);

	s_ar.push(ar_a);
	s_ar.push(ar_b);
	s_ar.push(ar_c);


	while (!s_ar.empty())
	{
		cout << s_ar.top();
		s_ar.pop();
	}

	int exit;

	cin >> exit;

	return 0;
}
