#include "register_types.h"

#include "globals.h"
#include "blitter.h"

void register_blitter_types() {
	_blitter = memnew(_Blitter);

	Globals::get_singleton()->add_singleton(Globals::Singleton("Blitter", _Blitter::get_singleton()));
}
void unregister_blitter_types() {
	memdelete(_blitter);
}
