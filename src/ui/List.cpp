#include "ui.hpp"


namespace rack {


void List::step() {
	Widget::step();

	// Set positions of children
	box.size.y = 0.0;
	for (Widget *child : children) {
		if (!child->visible)
			continue;
		// Increment height, set position of child
		child->box.pos = Vec(0.0, box.size.y);
		box.size.y += child->box.size.y;
		// Resize width of child
		child->box.size.x = box.size.x;
	}
}

void List::draw(NVGcontext *vg) {
	bndBackground(vg, 0.0, 0.0, box.size.x, box.size.y);
	bndBevel(vg, 0.0, 0.0, box.size.x, box.size.y);
	Widget::draw(vg);
}


} // namespace rack
