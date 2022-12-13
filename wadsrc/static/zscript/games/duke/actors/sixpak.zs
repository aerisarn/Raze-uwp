class DukeSixpak : DukeActor
{
	default
	{
		pic "SIXPAK";
	}
	
	override void Initialize()
	{
		commonItemSetup();
	}
}

class RedneckPorkRinds : DukeActor
{
	default
	{
		pic "SIXPAK";
	}
	
	override void Initialize()
	{
		commonItemSetup((0.203125, 0.140625));
		if (Raze.isRRRA()) self.cstat = CSTAT_SPRITE_BLOCK_HITSCAN;
	}
}
