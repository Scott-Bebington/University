#include <iostream>
#include <vector>

using namespace std;

class Player {
public:
	Player(string, int, int);
	int attack();
	void takeHit(int);
	bool isDead();
	string getName();
	int getHealth();
	int getSpeed();
	virtual ~Player();
protected:
	Player();
private:
	string name;
	int health;
	int speed;
};

Player::Player() {
	name = "No name";
	health = 10;
	speed = 10;
}

Player::Player(string name_, int health_ = 10, int speed_ = 10) {
	name = name_;
	health = health_;
	speed = speed_;
}

int Player::attack() {
	cout << "  " << name << " attacks" << endl;
	if (health == 0)
		return (rand() % abs(health+1)) - (abs(speed) % abs(health+1));
	return (rand() % abs(health)) - (abs(speed) % abs(health));
}

void Player::takeHit(int h){
	cout << "  " << name << " took a hit" << endl;
	health += h;
	speed += (h/2);
	if (speed < 0) speed = 0;
}

bool Player::isDead() {
	return health < 0;
}

string Player::getName() {
	return name;
}

int Player::getHealth() {
	return health;
}

int Player::getSpeed() {
	return speed;
}

Player::~Player() { }

class PlayerContext;

class PlayerState {
public:
	virtual bool action(PlayerContext*, Player*) = 0;
	virtual ~PlayerState() {};
};


class PlayerContext {
public:
	PlayerContext(Player*, PlayerState*);
	bool action(Player*);
	virtual ~PlayerContext();
	Player* getPlayer();
	void setPlayerState(PlayerState*);
protected:
	PlayerContext();
private:
	Player* player;
	PlayerState* pState;
};

PlayerContext::PlayerContext() {
	player = nullptr;
	pState = nullptr;
}

PlayerContext::PlayerContext(Player* p_, PlayerState* ps_) {
	player = p_;
	pState = ps_;
}

bool PlayerContext::action(Player* p_){
	return pState->action(this,p_);
}

Player* PlayerContext::getPlayer(){
	return player;
}

void PlayerContext::setPlayerState(PlayerState* ps_) {
	if (pState != nullptr)
		delete pState;
	pState = ps_;
}

PlayerContext::~PlayerContext() {
	delete pState;
}


class Advance : public PlayerState {
public:
	virtual bool action(PlayerContext*, Player*);
};

class Retreat : public PlayerState {
public:
	virtual bool action(PlayerContext*, Player*);
};

class Dead : public PlayerState {
public:
	virtual bool action(PlayerContext*, Player*);
};

bool Dead::action(PlayerContext* c_, Player* p_) {
	cout << "-- " << (c_->getPlayer())->getName() << " is dead " << endl;
	return false;
}




bool Advance::action(PlayerContext* c_, Player* p_) {
	cout << (c_->getPlayer())->getName() << " advances" << endl;
	int v = 0;
	v += (c_->getPlayer())->attack();
	v += (c_->getPlayer())->attack();
	p_->takeHit(v);
	if ((c_->getPlayer())->isDead()) {
		cout << "  --" << (c_->getPlayer())->getName() << " died" << endl;

		c_->setPlayerState(new Dead());
		//return false;
	} else {
		if ((c_->getPlayer())->getHealth() < 5) {
			cout << "  --" << (c_->getPlayer())->getName() << " is retreating" << endl;
			c_->setPlayerState(new Retreat());
		}
	}
	return true;
}



bool Retreat::action(PlayerContext* c_, Player* p_) {
	cout << (c_->getPlayer())->getName() << " retreats" << endl;
	(c_->getPlayer())->takeHit(2);
	int v = 0;
	v += p_->attack();
	(c_->getPlayer())->takeHit(v);
	if ((c_->getPlayer())->isDead()) {
		cout << "  --" << (c_->getPlayer())->getName() << " died" << endl;
		c_->setPlayerState(new Dead());
		//return false;
	} else {
		if ((c_->getPlayer())->getHealth() >= 15) {
			cout << "  --" << (c_->getPlayer())->getName() << " is advancing" << endl;
			c_->setPlayerState(new Advance());
		}
	}
	return true;
}





int main(){

	Player* redPlayer = new Player("Red", 15, 6);
	Player* blackPlayer = new Player("Black");
	
	PlayerContext* redContext = new PlayerContext(redPlayer, new Advance());
	PlayerContext* blackContext = new PlayerContext(blackPlayer, new Advance());
	
	srand(time(0));
	
	bool redAlive = true;
	bool blackAlive = true;
	while (redAlive && blackAlive) {
		redAlive = redContext->action(blackPlayer);
		if (redAlive && blackAlive)
			blackAlive = blackContext->action(redPlayer);
	}
	
    delete blackContext;
	delete redContext;
	
	delete blackPlayer;
	delete redPlayer;
    return 0; 
}
