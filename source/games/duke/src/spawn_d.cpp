//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment
Copyright (C) 2000, 2003 - Matt Saettler (EDuke Enhancements)
Copyright (C) 2020 - Christoph Oelckers

This file is part of Enhanced Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Original Source: 1996 - Todd Replogle
Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms

EDuke enhancements integrated: 04/13/2003 - Matt Saettler

Note: EDuke source was in transition.  Changes are in-progress in the
source as it is released.

*/
//-------------------------------------------------------------------------
#include <utility>
#include "ns.h"
#include "global.h"
#include "sounds.h"
#include "names_d.h"

BEGIN_DUKE_NS


int spawn_d(int j, int pn)
{
    int x;

	int i = initspriteforspawn(j, pn, { CRACK1, CRACK2, CRACK3, CRACK4, SPEAKER, LETTER, DUCK, TARGET, TRIPBOMB, VIEWSCREEN, VIEWSCREEN2 });
    if (!(i & 0x1000000)) return i;
    i &= 0xffffff;
    auto sp = &sprite[i];
    auto t = hittype[i].temp_data;
    int sect = sp->sectnum;


	if (isWorldTour()) 
    {
		switch (sp->picnum) 
        {
		case BOSS5STAYPUT:
			hittype[i].actorstayput = sp->sectnum;
		case FIREFLY:
		case BOSS5:
			if (sp->picnum == BOSS5 || sp->picnum == BOSS5STAYPUT) 
            {
				if (j >= 0 && sprite[j].picnum == RESPAWN)
					sp->pal = sprite[j].pal;
				if (sp->pal != 0) 
                {
					sp->clipdist = 80;
					sp->xrepeat = 40;
					sp->yrepeat = 40;
				} 
                else 
                {
					sp->xrepeat = 80;
					sp->yrepeat = 80;
					sp->clipdist = 164;
				}
			}
            else 
            {
				sp->xrepeat = 40;
				sp->yrepeat = 40;
				sp->clipdist = 80;
			}

			if (j >= 0)
				sp->lotag = 0;

			if ((sp->lotag > ud.player_skill) || ud.monsters_off) 
            {
				sp->xrepeat = sp->yrepeat = 0;
				changespritestat(i, 5);
				break;
			} 
            else 
            {
				makeitfall(i);

				sp->cstat |= 257;
				ps[connecthead].max_actors_killed++;

				if (j >= 0) {
					hittype[i].timetosleep = 0;
					fi.check_fta_sounds(i);
					changespritestat(i, 1);
				} else
					changespritestat(i, 2);
			}
			return i;
		case FIREFLYFLYINGEFFECT:
			sp->owner = j;
			changespritestat(i, 5);
			sp->xrepeat = 16;
			sp->yrepeat = 16;
			return i;
		case LAVAPOOLBUBBLE:
			if (sprite[j].xrepeat < 30)
				return i;
			sp->owner = j;
			changespritestat(i, 5);
			sp->x += krand() % 512 - 256;
			sp->y += krand() % 512 - 256;
			sp->xrepeat = 16;
			sp->yrepeat = 16;
			return i;
		case WHISPYSMOKE:
			changespritestat(i, 5);
			sp->x += krand() % 256 - 128;
			sp->y += krand() % 256 - 128;
			sp->xrepeat = 20;
			sp->yrepeat = 20;
			return i;
        case SERIOUSSAM:
			changespritestat(i, 2);
			sp->cstat = 257;
			sp->extra = 150;
			return i;
		}
	}

    switch(sp->picnum)
    {
            default:
				spawninitdefault(j, i);
                break;
            case FOF:
                sp->xrepeat = sp->yrepeat = 0;
                changespritestat(i,5);
                break;
            case WATERSPLASH2:
                if(j >= 0)
                {
                    setsprite(i,sprite[j].x,sprite[j].y,sprite[j].z);
                    sp->xrepeat = sp->yrepeat = 8+(krand()&7);
                }
                else sp->xrepeat = sp->yrepeat = 16+(krand()&15);

                sp->shade = -16;
                sp->cstat |= 128;
                if(j >= 0)
                {
                    if(sector[sprite[j].sectnum].lotag == 2)
                    {
                        sp->z = getceilzofslope(sp->sectnum,sp->x,sp->y)+(16<<8);
                        sp->cstat |= 8;
                    }
                    else if( sector[sprite[j].sectnum].lotag == 1)
                        sp->z = getflorzofslope(sp->sectnum,sp->x,sp->y);
                }

                if(sector[sect].floorpicnum == FLOORSLIME ||
                    sector[sect].ceilingpicnum == FLOORSLIME)
                        sp->pal = 7;
            case NEON1:
            case NEON2:
            case NEON3:
            case NEON4:
            case NEON5:
            case NEON6:
            case DOMELITE:
                if(sp->picnum != WATERSPLASH2)
                    sp->cstat |= 257;
            case NUKEBUTTON:
                if(sp->picnum == DOMELITE)
                    sp->cstat |= 257;
            case JIBS1:
            case JIBS2:
            case JIBS3:
            case JIBS4:
            case JIBS5:
            case JIBS6:
            case HEADJIB1:
            case ARMJIB1:
            case LEGJIB1:
            case LIZMANHEAD1:
            case LIZMANARM1:
            case LIZMANLEG1:
            case DUKETORSO:
            case DUKEGUN:
            case DUKELEG:
                changespritestat(i,5);
                break;
            case TONGUE:
                if(j >= 0)
                    sp->ang = sprite[j].ang;
                sp->z -= 38<<8;
                sp->zvel = 256-(krand()&511);
                sp->xvel = 64-(krand()&127);
                changespritestat(i,4);
                break;
            case NATURALLIGHTNING:
                sp->cstat &= ~257;
                sp->cstat |= 32768;
                break;
            case TRANSPORTERSTAR:
            case TRANSPORTERBEAM:
				spawntransporter(j, i, sp->picnum == TRANSPORTERBEAM);
                break;

            case FRAMEEFFECT1:
                if(j >= 0)
                {
                    sp->xrepeat = sprite[j].xrepeat;
                    sp->yrepeat = sprite[j].yrepeat;
                    t[1] = sprite[j].picnum;
                }
                else sp->xrepeat = sp->yrepeat = 0;

                changespritestat(i,5);

                break;

            case LASERLINE:
                sp->yrepeat = 6;
                sp->xrepeat = 32;

                if(lasermode == 1)
                    sp->cstat = 16 + 2;
                else if(lasermode == 0 || lasermode == 2)
                    sp->cstat = 16;
                else
                {
                    sp->xrepeat = 0;
                    sp->yrepeat = 0;
                }

                if(j >= 0) sp->ang = hittype[j].temp_data[5]+512;
                changespritestat(i,5);
                break;

            case FORCESPHERE:
                if(j == -1 )
                {
                    sp->cstat = (short) 32768;
                    changespritestat(i,2);
                }
                else
                {
                    sp->xrepeat = sp->yrepeat = 1;
                    changespritestat(i,5);
                }
                break;

            case BLOOD:
               sp->xrepeat = sp->yrepeat = 16;
               sp->z -= (26<<8);
               if( j >= 0 && sprite[j].pal == 6 )
                   sp->pal = 6;
               changespritestat(i,5);
               break;
            case LAVAPOOL:
                if (!isWorldTour()) // Twentieth Anniversary World Tour
                    return i;

            case BLOODPOOL:
            case PUKE:
				if (spawnbloodpoolpart1(j, i)) break;

                if(j >= 0 && sp->picnum != PUKE)
                {
                    if( sprite[j].pal == 1)
                        sp->pal = 1;
                    else if( sprite[j].pal != 6 && sprite[j].picnum != NUKEBARREL && sprite[j].picnum != TIRE )
                    {
                        if(sprite[j].picnum == FECES)
                            sp->pal = 7; // Brown
                        else sp->pal = 2; // Red
                    }
                    else sp->pal = 0;  // green

                    if(sprite[j].picnum == TIRE)
                        sp->shade = 127;
                }
                sp->cstat |= 32;
            case FECES:
                if( j >= 0)
                    sp->xrepeat = sp->yrepeat = 1;
                changespritestat(i,5);
                break;

            case BLOODSPLAT1:
            case BLOODSPLAT2:
            case BLOODSPLAT3:
            case BLOODSPLAT4:
                sp->cstat |= 16;
                sp->xrepeat = 7+(krand()&7);
                sp->yrepeat = 7+(krand()&7);
                sp->z -= (16<<8);
                if(j >= 0 && sprite[j].pal == 6)
                    sp->pal = 6;
                insertspriteq(i);
                changespritestat(i,5);
                break;

            case TRIPBOMB:
                if( sp->lotag > ud.player_skill )
                {
                    sp->xrepeat=sp->yrepeat=0;
                    changespritestat(i,5);
                    break;
                }

                sp->xrepeat=4;
                sp->yrepeat=5;

                sp->owner = i;
                sp->hitag = i;

                sp->xvel = 16;
                ssp(i,CLIPMASK0);
                hittype[i].temp_data[0] = 17;
                hittype[i].temp_data[2] = 0;
                hittype[i].temp_data[5] = sp->ang;

            case SPACEMARINE:
                if(sp->picnum == SPACEMARINE)
                {
                    sp->extra = 20;
                    sp->cstat |= 257;
                }
                changespritestat(i,2);
                break;

            case HYDRENT:
            case PANNEL1:
            case PANNEL2:
            case SATELITE:
            case FUELPOD:
            case SOLARPANNEL:
            case ANTENNA:
            case GRATE1:
            case CHAIR1:
            case CHAIR2:
            case CHAIR3:
            case BOTTLE1:
            case BOTTLE2:
            case BOTTLE3:
            case BOTTLE4:
            case BOTTLE5:
            case BOTTLE6:
            case BOTTLE7:
            case BOTTLE8:
            case BOTTLE10:
            case BOTTLE11:
            case BOTTLE12:
            case BOTTLE13:
            case BOTTLE14:
            case BOTTLE15:
            case BOTTLE16:
            case BOTTLE17:
            case BOTTLE18:
            case BOTTLE19:
            case OCEANSPRITE1:
            case OCEANSPRITE2:
            case OCEANSPRITE3:
            case OCEANSPRITE5:
            case MONK:
            case INDY:
            case LUKE:
            case JURYGUY:
            case SCALE:
            case VACUUM:
            case FANSPRITE:
            case CACTUS:
            case CACTUSBROKE:
            case HANGLIGHT:
            case FETUS:
            case FETUSBROKE:
            case CAMERALIGHT:
            case MOVIECAMERA:
            case IVUNIT:
            case POT1:
            case POT2:
            case POT3:
            case TRIPODCAMERA:
            case SUSHIPLATE1:
            case SUSHIPLATE2:
            case SUSHIPLATE3:
            case SUSHIPLATE4:
            case SUSHIPLATE5:
            case WAITTOBESEATED:
            case VASE:
            case PIPE1:
            case PIPE2:
            case PIPE3:
            case PIPE4:
            case PIPE5:
            case PIPE6:
                sp->clipdist = 32;
                sp->cstat |= 257;
            case OCEANSPRITE4:
                changespritestat(i,0);
                break;
            case FEMMAG1:
            case FEMMAG2:
                sp->cstat &= ~257;
                changespritestat(i,0);
                break;
            case DUKETAG:
            case SIGN1:
            case SIGN2:
                if(ud.multimode < 2 && sp->pal)
                {
                    sp->xrepeat = sp->yrepeat = 0;
                    changespritestat(i,5);
                }
                else sp->pal = 0;
                break;
            case MASKWALL1:
            case MASKWALL2:
            case MASKWALL3:
            case MASKWALL4:
            case MASKWALL5:
            case MASKWALL6:
            case MASKWALL7:
            case MASKWALL8:
            case MASKWALL9:
            case MASKWALL10:
            case MASKWALL11:
            case MASKWALL12:
            case MASKWALL13:
            case MASKWALL14:
            case MASKWALL15:
                j = sp->cstat&60;
                sp->cstat = j|1;
                changespritestat(i,0);
                break;
            case FOOTPRINTS:
            case FOOTPRINTS2:
            case FOOTPRINTS3:
            case FOOTPRINTS4:
				initfootprint(j, i);
                break;

            case FEM1:
            case FEM2:
            case FEM3:
            case FEM4:
            case FEM5:
            case FEM6:
            case FEM7:
            case FEM8:
            case FEM9:
            case FEM10:
            case PODFEM1:
            case NAKED1:
            case STATUE:
            case TOUGHGAL:
                sp->yvel = sp->hitag;
                sp->hitag = -1;
                if(sp->picnum == PODFEM1) sp->extra <<= 1;
            case BLOODYPOLE:

            case QUEBALL:
            case STRIPEBALL:

                if(sp->picnum == QUEBALL || sp->picnum == STRIPEBALL)
                {
                    sp->cstat = 256;
                    sp->clipdist = 8;
                }
                else
                {
                    sp->cstat |= 257;
                    sp->clipdist = 32;
                }

                changespritestat(i,2);
                break;

            case DUKELYINGDEAD:
                if(j >= 0 && sprite[j].picnum == APLAYER)
                {
                    sp->xrepeat = sprite[j].xrepeat;
                    sp->yrepeat = sprite[j].yrepeat;
                    sp->shade = sprite[j].shade;
                    sp->pal = ps[sprite[j].yvel].palookup;
                }
            case DUKECAR:
            case HELECOPT:
//                if(sp->picnum == HELECOPT || sp->picnum == DUKECAR) sp->xvel = 1024;
                sp->cstat = 0;
                sp->extra = 1;
                sp->xvel = 292;
                sp->zvel = 360;
            case RESPAWNMARKERRED:
            case BLIMP:

                if(sp->picnum == RESPAWNMARKERRED)
                {
                    sp->xrepeat = sp->yrepeat = 24;
                    if(j >= 0) sp->z = hittype[j].floorz; // -(1<<4);
                }
                else
                {
                    sp->cstat |= 257;
                    sp->clipdist = 128;
                }
            case MIKE:
                if(sp->picnum == MIKE)
                    sp->yvel = sp->hitag;
            case WEATHERWARN:
                changespritestat(i,1);
                break;

            case SPOTLITE:
                t[0] = sp->x;
                t[1] = sp->y;
                break;
            case BULLETHOLE:
                sp->xrepeat = sp->yrepeat = 3;
                sp->cstat = 16+(krand()&12);
                insertspriteq(i);
            case MONEY:
            case MAIL:
            case PAPER:
                if( sp->picnum == MONEY || sp->picnum == MAIL || sp->picnum == PAPER )
                {
                    hittype[i].temp_data[0] = krand()&2047;
                    sp->cstat = krand()&12;
                    sp->xrepeat = sp->yrepeat = 8;
                    sp->ang = krand()&2047;
                }
                changespritestat(i,5);
                break;

            case VIEWSCREEN:
            case VIEWSCREEN2:
                sp->owner = i;
                sp->lotag = 1;
                sp->extra = 1;
                changespritestat(i,6);
                break;

            case SHELL: //From the player
            case SHOTGUNSHELL:
				initshell(j, i, sp->picnum == SHELL);
                break;

            case RESPAWN:
                sp->extra = 66-13;
            case MUSICANDSFX:
                if( ud.multimode < 2 && sp->pal == 1)
                {
                    sp->xrepeat = sp->yrepeat = 0;
                    changespritestat(i,5);
                    break;
                }
                sp->cstat = (short)32768;
                changespritestat(i,11);
                break;

            case ONFIRE:
                // Twentieth Anniversary World Tour
                if (!isWorldTour())
                    break;

            case EXPLOSION2:
            case EXPLOSION2BOT:
            case BURNING:
            case BURNING2:
            case SMALLSMOKE:
            case SHRINKEREXPLOSION:
            case COOLEXPLOSION1:

                if(j >= 0)
                {
                    sp->ang = sprite[j].ang;
                    sp->shade = -64;
                    sp->cstat = 128|(krand()&4);
                }

                if(sp->picnum == EXPLOSION2 || sp->picnum == EXPLOSION2BOT)
                {
                    sp->xrepeat = 48;
                    sp->yrepeat = 48;
                    sp->shade = -127;
                    sp->cstat |= 128;
                }
                else if(sp->picnum == SHRINKEREXPLOSION )
                {
                    sp->xrepeat = 32;
                    sp->yrepeat = 32;
                }
                else if( sp->picnum == SMALLSMOKE )
                {
                    // 64 "money"
                    sp->xrepeat = 24;
                    sp->yrepeat = 24;
                }
                else if(sp->picnum == BURNING || sp->picnum == BURNING2)
                {
                    sp->xrepeat = 4;
                    sp->yrepeat = 4;
                }

                if(j >= 0)
                {
                    x = getflorzofslope(sp->sectnum,sp->x,sp->y);
                    if(sp->z > x-(12<<8) )
                        sp->z = x-(12<<8);
                }

                changespritestat(i,5);

                break;

            case PLAYERONWATER:
                if(j >= 0)
                {
                    sp->xrepeat = sprite[j].xrepeat;
                    sp->yrepeat = sprite[j].yrepeat;
                    sp->zvel = 128;
                    if(sector[sp->sectnum].lotag != 2)
                        sp->cstat |= 32768;
                }
                changespritestat(i,13);
                break;

            case APLAYER:
                sp->xrepeat = sp->yrepeat = 0;
                j = ud.coop;
                if(j == 2) j = 0;

                if( ud.multimode < 2 || (ud.multimode > 1 && j != sp->lotag) )
                    changespritestat(i,5);
                else
                    changespritestat(i,10);
                break;
            case WATERBUBBLE:
                if(j >= 0 && sprite[j].picnum == APLAYER)
                    sp->z -= (16<<8);
                if( sp->picnum == WATERBUBBLE)
                {
                    if( j >= 0 )
                        sp->ang = sprite[j].ang;
                    sp->xrepeat = sp->yrepeat = 4;
                }
                else sp->xrepeat = sp->yrepeat = 32;

                changespritestat(i,5);
                break;

            case CRANE:
				initcrane(j, i, CRANEPOLE);
                break;

            case WATERDRIP:
                initwaterdrip(j, i);
                break;
            case TRASH:

                if(sp->picnum != WATERDRIP)
                    sp->ang = krand()&2047;

            case WATERDRIPSPLASH:

                sp->xrepeat = 24;
                sp->yrepeat = 24;


                changespritestat(i,6);
                break;

            case PLUG:
                sp->lotag = 9999;
                changespritestat(i,6);
                break;
            case TOUCHPLATE:
                t[2] = sector[sect].floorz;
                if(sector[sect].lotag != 1 && sector[sect].lotag != 2)
                    sector[sect].floorz = sp->z;
                if (!isWorldTour())
                {
                    if (sp->pal && ud.multimode > 1)
                    {
                        sp->xrepeat = sp->yrepeat = 0;
                        changespritestat(i, 5);
                        break;
                    }
                }
                else { // Twentieth Anniversary World Tour addition
                    if ((sp->pal == 1 && ud.multimode > 1) // Single-game Only
                        || (sp->pal == 2 && (ud.multimode == 1 || ud.multimode > 1 && ud.coop != 1)) // Co-op Only
                        || (sp->pal == 3 && (ud.multimode == 1 || ud.multimode > 1 && ud.coop == 1))) // Dukematch Only
                    {
                        sp->xrepeat = sp->yrepeat = 0;
                        changespritestat(i, 5);
                        break;
                    }
                }
            case WATERBUBBLEMAKER:
				if (sp->hitag && sp->picnum == WATERBUBBLEMAKER) 
                {	// JBF 20030913: Pisses off move(), eg. in bobsp2
					Printf(TEXTCOLOR_YELLOW "WARNING: WATERBUBBLEMAKER %d @ %d,%d with hitag!=0. Applying fixup.\n",i,sp->x,sp->y);
					sp->hitag = 0;
				}
                sp->cstat |= 32768;
                changespritestat(i,6);
                break;
            case BOLT1:
            case BOLT1+1:
            case BOLT1+2:
            case BOLT1+3:
            case SIDEBOLT1:
            case SIDEBOLT1+1:
            case SIDEBOLT1+2:
            case SIDEBOLT1+3:
                t[0] = sp->xrepeat;
                t[1] = sp->yrepeat;
            case MASTERSWITCH:
                if(sp->picnum == MASTERSWITCH)
                    sp->cstat |= 32768;
                sp->yvel = 0;
                changespritestat(i,6);
                break;
            case TARGET:
            case DUCK:
            case LETTER:
                sp->extra = 1;
                sp->cstat |= 257;
                changespritestat(i,1);
                break;
            case OCTABRAINSTAYPUT:
            case LIZTROOPSTAYPUT:
            case PIGCOPSTAYPUT:
            case LIZMANSTAYPUT:
            case BOSS1STAYPUT:
            case PIGCOPDIVE:
            case COMMANDERSTAYPUT:
            case BOSS4STAYPUT:
                hittype[i].actorstayput = sp->sectnum;
            case BOSS1:
            case BOSS2:
            case BOSS3:
            case BOSS4:
            case ROTATEGUN:
            case GREENSLIME:
                if(sp->picnum == GREENSLIME)
                    sp->extra = 1;
            case DRONE:
            case LIZTROOPONTOILET:
            case LIZTROOPJUSTSIT:
            case LIZTROOPSHOOT:
            case LIZTROOPJETPACK:
            case LIZTROOPDUCKING:
            case LIZTROOPRUNNING:
            case LIZTROOP:
            case OCTABRAIN:
            case COMMANDER:
            case PIGCOP:
            case LIZMAN:
            case LIZMANSPITTING:
            case LIZMANFEEDING:
            case LIZMANJUMP:
            case ORGANTIC:
            case RAT:
            case SHARK:

                if(sp->pal == 0)
                {
                    switch(sp->picnum)
                    {
                        case LIZTROOPONTOILET:
                        case LIZTROOPSHOOT:
                        case LIZTROOPJETPACK:
                        case LIZTROOPDUCKING:
                        case LIZTROOPRUNNING:
                        case LIZTROOPSTAYPUT:
                        case LIZTROOPJUSTSIT:
                        case LIZTROOP:
                            sp->pal = 22;
                            break;
                    }
                }

                if( sp->picnum == BOSS4STAYPUT || sp->picnum == BOSS1 || sp->picnum == BOSS2 || sp->picnum == BOSS1STAYPUT || sp->picnum == BOSS3 || sp->picnum == BOSS4 )
                {
                    if(j >= 0 && sprite[j].picnum == RESPAWN)
                        sp->pal = sprite[j].pal;
                    if(sp->pal)
                    {
                        sp->clipdist = 80;
                        sp->xrepeat = 40;
                        sp->yrepeat = 40;
                    }
                    else
                    {
                        sp->xrepeat = 80;
                        sp->yrepeat = 80;
                        sp->clipdist = 164;
                    }
                }
                else
                {
                    if(sp->picnum != SHARK)
                    {
                        sp->xrepeat = 40;
                        sp->yrepeat = 40;
                        sp->clipdist = 80;
                    }
                    else
                    {
                        sp->xrepeat = 60;
                        sp->yrepeat = 60;
                        sp->clipdist = 40;
                    }
                }

                if(j >= 0) sp->lotag = 0;

                if( ( sp->lotag > ud.player_skill ) || ud.monsters_off == 1 )
                {
                    sp->xrepeat=sp->yrepeat=0;
                    changespritestat(i,5);
                    break;
                }
                else
                {
                    makeitfall(i);

                    if(sp->picnum == RAT)
                    {
                        sp->ang = krand()&2047;
                        sp->xrepeat = sp->yrepeat = 48;
                        sp->cstat = 0;
                    }
                    else
                    {
                        sp->cstat |= 257;

                        if(sp->picnum != SHARK)
                            ps[myconnectindex].max_actors_killed++;
                    }

                    if(sp->picnum == ORGANTIC) sp->cstat |= 128;

                    if(j >= 0)
                    {
                        hittype[i].timetosleep = 0;
                        fi.check_fta_sounds(i);
                        changespritestat(i,1);
                    }
                    else changespritestat(i,2);
                }

                if(sp->picnum == ROTATEGUN)
                    sp->zvel = 0;

                break;

            case LOCATORS:
                sp->cstat |= 32768;
                changespritestat(i,7);
                break;

            case ACTIVATORLOCKED:
            case ACTIVATOR:
                sp->cstat = (short) 32768;
                if(sp->picnum == ACTIVATORLOCKED)
                    sector[sp->sectnum].lotag |= 16384;
                changespritestat(i,8);
                break;

            case DOORSHOCK:
                sp->cstat |= 1+256;
                sp->shade = -12;
                changespritestat(i,6);
                break;

            case OOZ:
            case OOZ2:
                sp->shade = -12;

                if(j >= 0)
                {
                    if( sprite[j].picnum == NUKEBARREL )
                        sp->pal = 8;
                    insertspriteq(i);
                }

                changespritestat(i,1);

                getglobalz(i);

                j = (hittype[i].floorz-hittype[i].ceilingz)>>9;

                sp->yrepeat = j;
                sp->xrepeat = 25-(j>>1);
                sp->cstat |= (krand()&4);

                break;

            case HEAVYHBOMB:
                if(j >= 0)
                    sp->owner = j;
                else sp->owner = i;
                sp->xrepeat = sp->yrepeat = 9;
                sp->yvel = 4;
            case REACTOR2:
            case REACTOR:
            case RECON:
				if (initreactor(j, i, sp->picnum == RECON)) return i;
                break;

            case FLAMETHROWERSPRITE:
            case FLAMETHROWERAMMO: // Twentieth Anniversary World Tour
                if (!isWorldTour())
                    break;

            case ATOMICHEALTH:
            case STEROIDS:
            case HEATSENSOR:
            case SHIELD:
            case AIRTANK:
            case TRIPBOMBSPRITE:
            case JETPACK:
            case HOLODUKE:

            case FIRSTGUNSPRITE:
            case CHAINGUNSPRITE:
            case SHOTGUNSPRITE:
            case RPGSPRITE:
            case SHRINKERSPRITE:
            case FREEZESPRITE:
            case DEVISTATORSPRITE:

            case SHOTGUNAMMO:
            case FREEZEAMMO:
            case HBOMBAMMO:
            case CRYSTALAMMO:
            case GROWAMMO:
            case BATTERYAMMO:
            case DEVISTATORAMMO:
            case RPGAMMO:
            case BOOTS:
            case AMMO:
            case AMMOLOTS:
            case COLA:
            case FIRSTAID:
            case SIXPAK:
                if(j >= 0)
                {
                    sp->lotag = 0;
                    sp->z -= (32<<8);
                    sp->zvel = -1024;
                    ssp(i,CLIPMASK0);
                    sp->cstat = krand()&4;
                }
                else
                {
                    sp->owner = i;
                    sp->cstat = 0;
                }

                if( ( ud.multimode < 2 && sp->pal != 0) || (sp->lotag > ud.player_skill) )
                {
                    sp->xrepeat = sp->yrepeat = 0;
                    changespritestat(i,5);
                    break;
                }

                sp->pal = 0;

            case ACCESSCARD:

                if(sp->picnum == ATOMICHEALTH)
                    sp->cstat |= 128;

                if(ud.multimode > 1 && ud.coop != 1 && sp->picnum == ACCESSCARD)
                {
                    sp->xrepeat = sp->yrepeat = 0;
                    changespritestat(i,5);
                    break;
                }
                else
                {
                    if(sp->picnum == AMMO)
                        sp->xrepeat = sp->yrepeat = 16;
                    else sp->xrepeat = sp->yrepeat = 32;
                }

                sp->shade = -17;

                if(j >= 0) changespritestat(i,1);
                else
                {
                    changespritestat(i,2);
                    makeitfall(i);
                }
                break;

            case WATERFOUNTAIN:
                sp->lotag = 1;

            case TREE1:
            case TREE2:
            case TIRE:
            case CONE:
            case BOX:
                sp->cstat = 257; // Make it hitable
                sprite[i].extra = 1;
                changespritestat(i,6);
                break;

            case FLOORFLAME:
                sp->shade = -127;
                changespritestat(i,6);
                break;

            case BOUNCEMINE:
                sp->owner = i;
                sp->cstat |= 1+256; //Make it hitable
                sp->xrepeat = sp->yrepeat = 24;
                sp->shade = -127;
                sp->extra = impact_damage<<2;
                changespritestat(i,2);
                break;

            case CAMERA1:
            case CAMERA1+1:
            case CAMERA1+2:
            case CAMERA1+3:
            case CAMERA1+4:
            case CAMERAPOLE:
                sp->extra = 1;

                if(camerashitable) sp->cstat = 257;
                else sp->cstat = 0;

            case GENERICPOLE:

                if( ud.multimode < 2 && sp->pal != 0 )
                {
                    sp->xrepeat = sp->yrepeat = 0;
                    changespritestat(i,5);
                    break;
                }
                else sp->pal = 0;
                if(sp->picnum == CAMERAPOLE || sp->picnum == GENERICPOLE) break;
                sp->picnum = CAMERA1;
                changespritestat(i,1);
                break;
            case STEAM:
                if(j >= 0)
                {
                    sp->ang = sprite[j].ang;
                    sp->cstat = 16+128+2;
                    sp->xrepeat=sp->yrepeat=1;
                    sp->xvel = -8;
                    ssp(i,CLIPMASK0);
                }
            case CEILINGSTEAM:
                changespritestat(i,6);
                break;

            case SECTOREFFECTOR:
				spawneffector(i);

                break;


            case SEENINE:
            case OOZFILTER:

                sp->shade = -16;
                if(sp->xrepeat <= 8)
                {
                    sp->cstat = (short)32768;
                    sp->xrepeat=sp->yrepeat=0;
                }
                else sp->cstat = 1+256;
                sp->extra = impact_damage<<2;
                sp->owner = i;

                changespritestat(i,6);
                break;

            case CRACK1:
            case CRACK2:
            case CRACK3:
            case CRACK4:
            case FIREEXT:
                if(sp->picnum == FIREEXT)
                {
                    sp->cstat = 257;
                    sp->extra = impact_damage<<2;
                }
                else
                {
                    sp->cstat |= (sp->cstat & 48) ? 1 : 17;
                    sp->extra = 1;
                }

                if( ud.multimode < 2 && sp->pal != 0)
                {
                    sp->xrepeat = sp->yrepeat = 0;
                    changespritestat(i,5);
                    break;
                }

                sp->pal = 0;
                sp->owner = i;
                changespritestat(i,6);
                sp->xvel = 8;
                ssp(i,CLIPMASK0);
                break;

            case TOILET:
            case STALL:
                sp->lotag = 1;
                sp->cstat |= 257;
                sp->clipdist = 8;
                sp->owner = i;
                break;
            case CANWITHSOMETHING:
            case CANWITHSOMETHING2:
            case CANWITHSOMETHING3:
            case CANWITHSOMETHING4:
            case RUBBERCAN:
                sp->extra = 0;
            case EXPLODINGBARREL:
            case HORSEONSIDE:
            case FIREBARREL:
            case NUKEBARREL:
            case FIREVASE:
            case NUKEBARRELDENTED:
            case NUKEBARRELLEAKED:
            case WOODENHORSE:

                if(j >= 0)
                    sp->xrepeat = sp->yrepeat = 32;
                sp->clipdist = 72;
                makeitfall(i);
                if(j >= 0)
                    sp->owner = j;
                else sp->owner = i;
            case EGG:
                if( ud.monsters_off == 1 && sp->picnum == EGG )
                {
                    sp->xrepeat = sp->yrepeat = 0;
                    changespritestat(i,5);
                }
                else
                {
                    if(sp->picnum == EGG)
                        sp->clipdist = 24;
                    sp->cstat = 257|(krand()&4);
                    changespritestat(i,2);
                }
                break;
            case TOILETWATER:
                sp->shade = -16;
                changespritestat(i,6);
                break;
    }
    return i;
}

END_DUKE_NS
