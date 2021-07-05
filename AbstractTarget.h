#pragma once
// абстрактна мішень
class AbstractTarget
{
public:
	AbstractTarget();
	AbstractTarget(size_t, int);
	size_t currentShotsCount;// = 0;

	bool canShot() const;

	size_t GetMaxShotsCount() const;
	int GetMaxRange() const;

	void SetMaxShotsCount(size_t);
	void SetMaxRange(int);

	virtual float Shot(int x, int y) abstract;
	// характеристики мишени
private:
	size_t maxShotsCount;
protected:
	//size_t currentShotsCount;// = 0;
	int maxRange;
};

