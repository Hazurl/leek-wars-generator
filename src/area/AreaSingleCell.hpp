#ifndef SRC_AREA_AREASINGLECELL_HPP_
#define SRC_AREA_AREASINGLECELL_HPP_

#include "Area.hpp"

class AreaSingleCell: public Area {
public:
	AreaSingleCell(Attack* attack);
	virtual ~AreaSingleCell();

	virtual std::vector<Cell*> getArea(Cell* launch, Cell* target) const override;

	virtual int getRadius() const override;
};

#endif
