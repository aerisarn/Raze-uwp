class DukeBoss2 : DukeBoss1
{
	default
	{
		pic "BOSS2";
	}
	
	override void PlayFTASound()
	{
		if (self.pal == 1)
			Duke.PlaySound("BOS2_RECOG");
		else Duke.PlaySound("WHIPYOURASS");
	}
}


class DukeBoss2Stayput : DukeBoss2
{
	default
	{
		pic "BOSS2STAYPUT";
	}
}
	
