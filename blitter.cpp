#include "blitter.h"

_Blitter *_Blitter::singleton = NULL;

void _Blitter::_bind_methods() {
    ObjectTypeDB::bind_method(_MD("calculate_new_rect_from_mins_max", "p_base_size", "p_mins", "p_max"), &_Blitter::calculate_new_rect_from_mins_max);
    ObjectTypeDB::bind_method(_MD("calculate_new_size_from_mins_max", "p_base_size", "p_mins", "p_max"), &_Blitter::calculate_new_size_from_mins_max);
	ObjectTypeDB::bind_method(_MD("blit_rect_modulate", "p_src:Image", "p_src_rect", "p_dest_point", "p_modulate"), &_Blitter::blit_rect_modulate);
	ObjectTypeDB::bind_method(_MD("blit_rect_modulate_inverted_alpha", "p_src:Image", "p_src_rect", "p_dest_point", "p_modulate"), &_Blitter::blit_rect_modulate_inverted_alpha);
	ObjectTypeDB::bind_method(_MD("blit_rect_modulate_inverted_alpha_translucent", "p_src:Image", "p_src_rect", "p_dest_point", "p_modulate"), &_Blitter::blit_rect_modulate_inverted_alpha_translucent);
}

_Blitter *_Blitter::get_singleton() {
	return singleton;
}

Rect2 _Blitter::calculate_new_rect_from_mins_max(const Vector2 &p_base_size, const Vector2 &p_mins, const Vector2 &p_max) {
	return Blitter::calculate_new_rect_from_mins_max(p_base_size, p_mins, p_max);
}

Vector2 _Blitter::calculate_new_size_from_mins_max(const Vector2 &p_base_size, const Vector2 &p_mins, const Vector2 &p_max) {
	return Blitter::calculate_new_size_from_mins_max(p_base_size, p_mins, p_max);
}

Image _Blitter::blit_rect_modulate(const Image& p_src, const Rect2& p_src_rect, const Image& p_dest, const Point2& p_dest_point, const Color &p_modulate) {
	return Blitter::blit_rect<true, false, false>(p_src, p_src_rect, p_dest, p_dest_point, p_modulate);
}

Image _Blitter::blit_rect_modulate_inverted_alpha(const Image& p_src, const Rect2& p_src_rect, const Image& p_dest, const Point2& p_dest_point, const Color &p_modulate) {
	return Blitter::blit_rect<true, true, false>(p_src, p_src_rect, p_dest, p_dest_point, p_modulate);
}

Image _Blitter::blit_rect_modulate_inverted_alpha_translucent(const Image& p_src, const Rect2& p_src_rect, const Image& p_dest, const Point2& p_dest_point, const Color &p_modulate) {
	return Blitter::blit_rect<true, true, true>(p_src, p_src_rect, p_dest, p_dest_point, p_modulate);
}

_Blitter::_Blitter() {
	singleton = this;
}
