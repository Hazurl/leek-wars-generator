package com.leekwars.game.fight.action;

import com.alibaba.fastjson.JSONArray;
import com.leekwars.game.Util;
import com.leekwars.game.fight.entity.Entity;

public class ActionShowCell implements Action {

	private final int mLeek;
	private final int mCell;
	private final int mColor;

	public ActionShowCell(Entity l, int cell, int color) {
		mLeek = l.getFId();
		mCell = cell;
		mColor = color;
	}

	@Override
	public JSONArray getJSON() {
		JSONArray retour = new JSONArray();
		retour.add(Action.SHOW_CELL);
		retour.add(mLeek);
		retour.add(mCell);
		retour.add(Util.getHexaColor(mColor));

		return retour;
	}
}
