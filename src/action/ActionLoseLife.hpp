#ifndef ACTION_LOSE_LIFE
#define ACTION_LOSE_LIFE

#include "Action.hpp"
#include "../entity/Entity.hpp"

class ActionLoseLife : public Action {
	int target;
	int life;
public:

	ActionLoseLife(Entity* target, int life);

	virtual Json json() const override;
};

#endif
