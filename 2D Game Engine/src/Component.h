#pragma once
class Component
{
public:
	// Constructor
	Component(class Actor* owner, int updateOrder = 10);
	virtual ~Component();

	virtual void Update(float deltaTime);
	int GetUpdateOrder() const { return mUpdateOrder; }

protected:
	// Owning Actor
	class Actor* mOwner;
	// Update order of component
	int mUpdateOrder;
};

