#include <iostream>
#include <vector>
#include <stack>   
#include <queue> 
#include <memory>
#include <algorithm>

using namespace std;

// declare enemy class

class Enemy
{
public:
	Enemy(int hps);
	Enemy();
	Enemy(const Enemy& src);
	Enemy& operator=(const Enemy& src);
	virtual ~Enemy();

	virtual int get_hit_points() const;
	virtual int get_score() const;
	virtual void set_hit_points(int new_hit_points);
	virtual	void set_score(int new_score);

	friend bool operator<(const Enemy& a, const Enemy& b);
protected:
	int hit_points;
	//shared_ptr<int> score;
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

Enemy::Enemy(const Enemy & src):
	hit_points(src.hit_points),
	score(new int(*src.score))
{

}

Enemy & Enemy::operator=(const Enemy & src)
{
	// TODO: insert return statement here
	if (this == &src) return (*this);

	delete score;

	score = new int(src.get_score());
	hit_points = src.get_hit_points();

	return *this;
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

bool operator<(const Enemy& a, const Enemy& b)
{
	//int a_hp = a.get_hit_points;
	//int b_hp = b.get_hit_points;
	if (a.get_hit_points()< b.get_hit_points())
	{
		return true;
	}

	else 
	{
		return false;
	}
}

// declare flying enemy class

class ArmedEnemy : public Enemy
{
public:
	ArmedEnemy(int hps, int ammo);
	ArmedEnemy();
	ArmedEnemy(const ArmedEnemy& src);
	ArmedEnemy& operator=(const ArmedEnemy& src);
	virtual ~ArmedEnemy();
	virtual void set_score( int new_score);
	virtual void shoot();
	friend ostream& operator<<(ostream& ostr, const ArmedEnemy arm_e);
	friend bool operator<(const ArmedEnemy& a, const ArmedEnemy& b);
protected:
	int ammo_level;
};

// define flying enemy class

ArmedEnemy::ArmedEnemy(int hps, int ammo) :
	Enemy(hps),
	ammo_level(ammo)
{
}

ArmedEnemy::ArmedEnemy():Enemy(2)
{
	ammo_level = 3;
}

ArmedEnemy::ArmedEnemy(const ArmedEnemy & src):
	Enemy(src),ammo_level(src.ammo_level)
{

}

ArmedEnemy & ArmedEnemy::operator=(const ArmedEnemy & src)
{
	// TODO: insert return statement here
	if (this == &src) return (*this);
	Enemy::operator=(src);

	ammo_level = src.ammo_level;

	return *this;
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
	ostr << "this ArmedEnemy have " << arm_e.get_hit_points() << " hit points and " << arm_e.get_score() << " scores" << "\n";
	//ostr << "this ArmedEnemy have";
	return ostr;
}

bool operator<(const ArmedEnemy& a, const ArmedEnemy& b)
{
	if (a.get_hit_points()< b.get_hit_points())
	{
		return true;
	}

	else
	{
		return false;
	}
}


class Boss : public ArmedEnemy
{
public:
	Boss(int hps, int ammo,int add_ammo);
	virtual ~Boss();
	int get_additional_armour() const;
	void set_additional_armour(int new_additional_armour);
protected:
	int additional_armour_level;
};



Boss::Boss(int hps, int ammo, int add_ammo) : 
	ArmedEnemy(hps, ammo),
	additional_armour_level(add_ammo)
{

}

Boss::~Boss()
{
}

int Boss::get_additional_armour() const
{
	return additional_armour_level;
}

void Boss::set_additional_armour(int new_additional_armour)
{
	additional_armour_level = new_additional_armour;
}

void some_function(Enemy& enemy)
{
	enemy.set_score(6);
}


void decrementing_hit_point(Enemy e)
{
	int value = e.get_hit_points();
	value = value - 1;
	//e.set_hit_points(value);
}


int main(void)
{

	ArmedEnemy* ae = new ArmedEnemy(2, 5);
	ae->set_hit_points(3);
	cout << "hit points = " << ae->get_hit_points() << "\n";

	ae->shoot();

	some_function(*ae);

	Boss* b1 = new Boss(5, 3, 2);

	cout << "Boss have " << b1->get_additional_armour() << " armours";

	b1->set_additional_armour(10);

	cout << "Boss have " << b1->get_additional_armour() << " armours";


	delete b1;
	delete ae;
	ae = NULL;
	b1 = NULL;

	//Exercise 4

	ArmedEnemy arr[10];

	Boss b2(5, 3, 3);



	Enemy *arr_enemy[11];


	for (int i = 0; i < 10; i++)
	{
		arr_enemy[i] = &arr[i];
	}

	arr_enemy[10] = &b2;

	for (int i = 0; i < 11; i++)
	{
		decrementing_hit_point(*arr_enemy[i]);
		cout << "enemy" << i << "have " << arr_enemy[i]->get_hit_points() << "(s)" << endl;

	}

	//Exercise for Operator Over;oading

	ArmedEnemy arm_e1(3, 5);

	cout << arm_e1;


	//Exercise 3 of Vector

	//bool check;
	stack<ArmedEnemy> s_ar;
	queue<ArmedEnemy> q_ar;
	stack<ArmedEnemy> s_ar_a;



	ArmedEnemy ar_a(5, 5);
	ArmedEnemy ar_b(5, 4);
	ArmedEnemy ar_c(4, 5);

	s_ar.push(ar_a);
	s_ar.push(ar_b);
	s_ar.push(ar_c);


	//s_ar_a.push(ar_c);
	//s_ar_a.pop();

	//check = s_ar.empty();

	while (!s_ar.empty())
	{
		cout << s_ar.top();
		s_ar.pop();
	}
	
	cout << "The stack is empty." << "\n" << endl;

	//check = s_ar.empty();

	q_ar.emplace(ar_a);
	q_ar.emplace(ar_b);
	q_ar.emplace(ar_c);

	while (!q_ar.empty())
	{
		std::cout << q_ar.front();
		q_ar.pop();
	}

	cout << "The queue is empty." << "\n" << endl;

	//Exercise 4 of Vector
	vector<ArmedEnemy> v_arStack(10);
	//vector<ArmedEnemy>* v_arHeap = new vector<ArmedEnemy>(10);

		int i = 0;
	for (vector<ArmedEnemy>::iterator it = v_arStack.begin(); it != v_arStack.end(); it++)
	{

		it->set_hit_points(i);
		cout << it->get_hit_points() << endl;
		i++;
	}
	cout << "this sequence is end." << "\n" << endl;

	random_shuffle(v_arStack.begin(), v_arStack.end());

	for (vector<ArmedEnemy>::iterator it = v_arStack.begin(); it != v_arStack.end(); it++)
	{
		cout << it->get_hit_points() << endl;
	}
	cout << "this sequence is end." << "\n" << endl;

	sort(v_arStack.begin(), v_arStack.end());
	for (vector<ArmedEnemy>::iterator it = v_arStack.begin(); it != v_arStack.end(); it++)
	{
		cout << it->get_hit_points() << endl;
	}
	cout << "this sequence is end." << "\n" << endl;

	int exit;

	std::cin >> exit;

	return 0;
}
