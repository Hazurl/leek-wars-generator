#include "FightModule.hpp"
#include "../fight/Simulator.hpp"
#include "../entity/Entity.hpp"
#include "../fight/Fight.hpp"

/*
 * class Fight {
 * 		enum Type {
 * 			SOLO, FARMER, TEAM, BR
 * 		}
 * 		enum Context {
 * 			TEST, GARDEN, CHALLENGE
 * 		}
 * }
 *
 * Fight.Type.SOLO
 * let ctx = Fight.Context.GARDEN
 */

FightModule::FightModule() : Module("Fight") {

	static_field("MAX_TURNS", ls::Type::INTEGER, [](ls::Compiler& c) { return c.new_integer(64); });

	method("getTurn", ls::Method::Static, {{ls::Type::INTEGER, {}, (void*) &fight_getTurn}});
	method("getEntity", ls::Method::Static, {
		{EntityModule::type_ptr, {}, (void*) &fight_getEntity, ls::Method::NATIVE}
	});
	method("getType", ls::Method::Static, {{ls::Type::INTEGER, {}, (void*) &fight_getType}});
	method("getContext", ls::Method::Static, {{ls::Type::INTEGER, {}, (void*) &fight_getContext}});
}

FightModule::~FightModule() {}

int fight_getTurn() {
	return Simulator::fight->turn;
}

Entity* fight_getEntity() {
	return Simulator::entity;
}

int fight_getType() {
	return Simulator::fight->type;
}

int fight_getContext() {
	return Simulator::fight->context;
}
