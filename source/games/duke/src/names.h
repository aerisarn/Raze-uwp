//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

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
*/
//-------------------------------------------------------------------------
#pragma once

BEGIN_DUKE_NS

enum
{
	SECTOREFFECTOR = 1,
	ACTIVATOR = 2,
	TOUCHPLATE = 3,
	ACTIVATORLOCKED = 4,
	MUSICANDSFX = 5,
	LOCATORS = 6,
	CYCLER = 7,
	MASTERSWITCH = 8,
	RESPAWN = 9,
	GPSPEED = 10,
	FOF = 13,
	ARROW = 20,
	FIRSTGUNSPRITE = 21,
	CHAINGUNSPRITE = 22,
	RPGSPRITE = 23,
	FREEZESPRITE = 24,
	SHRINKERSPRITE = 25,
	HEAVYHBOMB = 26,
	TRIPBOMBSPRITE = 27,
	SHOTGUNSPRITE = 28,
	DEVISTATORSPRITE = 29,
	HEALTHBOX = 30,
	AMMOBOX = 31,
	GROWSPRITEICON = 32,
	INVENTORYBOX = 33,
	FREEZEAMMO = 37,
	AMMO = 40,
	BATTERYAMMO = 41,
	DEVISTATORAMMO = 42,
	RPGAMMO = 44,
	GROWAMMO = 45,
	CRYSTALAMMO = 46,
	HBOMBAMMO = 47,
	AMMOLOTS = 48,
	SHOTGUNAMMO = 49,
	COLA = 51,
	SIXPAK = 52,
	FIRSTAID = 53,
	SHIELD = 54,
	STEROIDS = 55,
	AIRTANK = 56,
	JETPACK = 57,
	HEATSENSOR = 59,
	ACCESSCARD = 60,
	BOOTS = 61,
	MIRRORBROKE = 70,
	CLOUDYOCEAN = 78,
	CLOUDYSKIES = 79,
	MOONSKY1 = 80,
	MOONSKY2 = 81,
	MOONSKY3 = 82,
	MOONSKY4 = 83,
	BIGORBIT1 = 84,
	BIGORBIT2 = 85,
	BIGORBIT3 = 86,
	BIGORBIT4 = 87,
	BIGORBIT5 = 88,
	LA = 89,
	REDSKY1 = 98,
	REDSKY2 = 99,
	ATOMICHEALTH = 100,
	TECHLIGHT2 = 120,
	TECHLIGHTBUST2 = 121,
	TECHLIGHT4 = 122,
	TECHLIGHTBUST4 = 123,
	WALLLIGHT4 = 124,
	WALLLIGHTBUST4 = 125,
	ACCESSSWITCH = 130,
	SLOTDOOR = 132,
	LIGHTSWITCH = 134,
	SPACEDOORSWITCH = 136,
	SPACELIGHTSWITCH = 138,
	FRANKENSTINESWITCH = 140,
	NUKEBUTTON = 142,
	MULTISWITCH = 146,
	DOORTILE5 = 150,
	DOORTILE6 = 151,
	DOORTILE1 = 152,
	DOORTILE2 = 153,
	DOORTILE3 = 154,
	DOORTILE4 = 155,
	DOORTILE7 = 156,
	DOORTILE8 = 157,
	DOORTILE9 = 158,
	DOORTILE10 = 159,
	DOORSHOCK = 160,
	DIPSWITCH = 162,
	DIPSWITCH2 = 164,
	TECHSWITCH = 166,
	DIPSWITCH3 = 168,
	ACCESSSWITCH2 = 170,
	REFLECTWATERTILE = 180,
	FLOORSLIME = 200,
	BIGFORCE = 230,
	EPISODE = 247,
	MASKWALL9 = 255,
	W_LIGHT = 260,
	SCREENBREAK1 = 263,
	SCREENBREAK2 = 264,
	SCREENBREAK3 = 265,
	SCREENBREAK4 = 266,
	SCREENBREAK5 = 267,
	SCREENBREAK6 = 268,
	SCREENBREAK7 = 269,
	SCREENBREAK8 = 270,
	SCREENBREAK9 = 271,
	SCREENBREAK10 = 272,
	SCREENBREAK11 = 273,
	SCREENBREAK12 = 274,
	SCREENBREAK13 = 275,
	MASKWALL1 = 285,
	W_TECHWALL1 = 293,
	W_TECHWALL2 = 297,
	W_TECHWALL15 = 299,
	W_TECHWALL3 = 301,
	W_TECHWALL4 = 305,
	W_TECHWALL10 = 306,
	W_TECHWALL16 = 307,
	WATERTILE2 = 336,
	BPANNEL1 = 341,
	PANNEL1 = 342,
	PANNEL2 = 343,
	WATERTILE = 344,
	STATIC = 351,
	W_SCREENBREAK = 357,
	W_HITTECHWALL3 = 360,
	W_HITTECHWALL4 = 361,
	W_HITTECHWALL2 = 362,
	W_HITTECHWALL1 = 363,
	MASKWALL10 = 387,
	MASKWALL11 = 391,
	DOORTILE22 = 395,
	FANSPRITE = 407,
	FANSPRITEBROKE = 411,
	FANSHADOW = 412,
	FANSHADOWBROKE = 416,
	DOORTILE18 = 447,
	DOORTILE19 = 448,
	DOORTILE20 = 449,
	SPACESHUTTLE = 487,
	SATELLITE = 489,
	VIEWSCREEN2 = 499,
	VIEWSCREENBROKE = 501,
	VIEWSCREEN = 502,
	GLASS = 503,
	GLASS2 = 504,
	STAINGLASS1 = 510,
	MASKWALL5 = 514,
	SATELITE = 516,
	FUELPOD = 517,
	SLIMEPIPE = 538,
	CRACK1 = 546,
	CRACK2 = 547,
	CRACK3 = 548,
	CRACK4 = 549,
	FOOTPRINTS = 550,
	DOMELITE = 551,
	CAMERAPOLE = 554,
	CHAIR1 = 556,
	CHAIR2 = 557,
	BROKENCHAIR = 559,
	MIRROR = 560,
	WATERFOUNTAIN = 563,
	WATERFOUNTAINBROKE = 567,
	FEMMAG1 = 568,
	TOILET = 569,
	STALL = 571,
	STALLBROKE = 573,
	FEMMAG2 = 577,
	REACTOR2 = 578,
	REACTOR2BURNT = 579,
	REACTOR2SPARK = 580,
	GRATE1 = 595,
	BGRATE1 = 596,
	SOLARPANNEL = 602,
	NAKED1 = 603,
	ANTENNA = 607,
	MASKWALL12 = 609,
	TOILETBROKE = 615,
	PIPE2 = 616,
	PIPE1B = 617,
	PIPE3 = 618,
	PIPE1 = 619,
	DUKE_CAMERA1 = 621,
	BRICK = 626,
	SPLINTERWOOD = 630,
	PIPE2B = 633,
	BOLT1 = 634,
	W_NUMBERS = 640,
	WATERDRIP = 660,
	WATERBUBBLE = 661,
	WATERBUBBLEMAKER = 662,
	W_FORCEFIELD = 663,
	VACUUM = 669,
	FOOTPRINTS2 = 672,
	FOOTPRINTS3 = 673,
	FOOTPRINTS4 = 674,
	EGG = 675,
	SCALE = 678,
	CHAIR3 = 680,
	CAMERALIGHT = 685,
	MOVIECAMERA = 686,
	IVUNIT = 689,
	POT1 = 694,
	POT2 = 695,
	POT3 = 697,
	PIPE3B = 700,
	WALLLIGHT3 = 701,
	WALLLIGHTBUST3 = 702,
	WALLLIGHT1 = 703,
	WALLLIGHTBUST1 = 704,
	WALLLIGHT2 = 705,
	WALLLIGHTBUST2 = 706,
	LIGHTSWITCH2 = 712,
	WAITTOBESEATED = 716,
	DOORTILE14 = 717,
	STATUE = 753,
	MIKE = 762,
	VASE = 765,
	SUSHIPLATE1 = 768,
	SUSHIPLATE2 = 769,
	SUSHIPLATE3 = 774,
	SUSHIPLATE4 = 779,
	DOORTILE16 = 781,
	SUSHIPLATE5 = 792,
	OJ = 806,
	MASKWALL13 = 830,
	HURTRAIL = 859,
	POWERSWITCH1 = 860,
	LOCKSWITCH1 = 862,
	POWERSWITCH2 = 864,
	ATM = 867,
	STATUEFLASH = 869,
	ATMBROKE = 888,
	BIGHOLE2 = 893,
	STRIPEBALL = 901,
	QUEBALL = 902,
	POCKET = 903,
	WOODENHORSE = 904,
	TREE1 = 908,
	TREE2 = 910,
	CACTUS = 911,
	MASKWALL2 = 913,
	MASKWALL3 = 914,
	MASKWALL4 = 915,
	FIREEXT = 916,
	TOILETWATER = 921,
	NEON1 = 925,
	NEON2 = 926,
	CACTUSBROKE = 939,
	BOUNCEMINE = 940,
	BROKEFIREHYDRENT = 950,
	BOX = 951,
	BULLETHOLE = 952,
	BOTTLE1 = 954,
	BOTTLE2 = 955,
	BOTTLE3 = 956,
	BOTTLE4 = 957,
	FEMPIC5 = 963,
	FEMPIC6 = 964,
	FEMPIC7 = 965,
	HYDROPLANT = 969,
	OCEANSPRITE1 = 971,
	OCEANSPRITE2 = 972,
	OCEANSPRITE3 = 973,
	OCEANSPRITE4 = 974,
	OCEANSPRITE5 = 975,
	GENERICPOLE = 977,
	CONE = 978,
	HANGLIGHT = 979,
	HYDRENT = 981,
	MASKWALL14 = 988,
	TIRE = 990,
	PIPE5 = 994,
	PIPE6 = 995,
	PIPE4 = 996,
	PIPE4B = 997,
	BROKEHYDROPLANT = 1003,
	PIPE5B = 1005,
	NEON3 = 1007,
	NEON4 = 1008,
	NEON5 = 1009,
	BOTTLE5 = 1012,
	BOTTLE6 = 1013,
	BOTTLE8 = 1014,
	SPOTLITE = 1020,
	HANGOOZ = 1022,
	MASKWALL15 = 1024,
	BOTTLE7 = 1025,
	HORSEONSIDE = 1026,
	GLASSPIECES = 1031,
	HORSELITE = 1034,
	DONUTS = 1045,
	NEON6 = 1046,
	MASKWALL6 = 1059,
	CLOCK = 1060,
	RUBBERCAN = 1062,
	BROKENCLOCK = 1067,
	PLUG = 1069,
	OOZFILTER = 1079,
	FLOORPLASMA = 1082,
	REACTOR = 1088,
	REACTORSPARK = 1092,
	REACTORBURNT = 1096,
	DOORTILE15 = 1102,
	HANDSWITCH = 1111,
	CIRCLEPANNEL = 1113,
	CIRCLEPANNELBROKE = 1114,
	PULLSWITCH = 1122,
	MASKWALL8 = 1124,
	BIGHOLE = 1141,
	ALIENSWITCH = 1142,
	DOORTILE21 = 1144,
	HANDPRINTSWITCH = 1155,
	BOTTLE10 = 1157,
	BOTTLE11 = 1158,
	BOTTLE12 = 1159,
	BOTTLE13 = 1160,
	BOTTLE14 = 1161,
	BOTTLE15 = 1162,
	BOTTLE16 = 1163,
	BOTTLE17 = 1164,
	BOTTLE18 = 1165,
	BOTTLE19 = 1166,
	DOORTILE17 = 1169,
	MASKWALL7 = 1174,
	JAILBARBREAK = 1175,
	DOORTILE11 = 1178,
	DOORTILE12 = 1179,
	VENDMACHINE = 1212,
	VENDMACHINEBROKE = 1214,
	COLAMACHINE = 1215,
	COLAMACHINEBROKE = 1217,
	CRANEPOLE = 1221,
	CRANE = 1222,
	BARBROKE = 1225,
	BLOODPOOL = 1226,
	NUKEBARREL = 1227,
	NUKEBARRELDENTED = 1228,
	NUKEBARRELLEAKED = 1229,
	CANWITHSOMETHING = 1232,
	MONEY = 1233,
	BANNER = 1236,
	EXPLODINGBARREL = 1238,
	EXPLODINGBARREL2 = 1239,
	FIREBARREL = 1240,
	SEENINE = 1247,
	SEENINEDEAD = 1248,
	STEAM = 1250,
	CEILINGSTEAM = 1255,
	PIPE6B = 1260,
	TRANSPORTERBEAM = 1261,
	RAT = 1267,
	TRASH = 1272,
	FEMPIC1 = 1280,
	FEMPIC2 = 1289,
	BLANKSCREEN = 1293,
	PODFEM1 = 1294,
	FEMPIC3 = 1298,
	FEMPIC4 = 1306,
	FEM1 = 1312,
	FEM2 = 1317,
	FEM3 = 1321,
	FEM5 = 1323,
	BLOODYPOLE = 1324,
	FEM4 = 1325,
	FEM6 = 1334,
	FEM6PAD = 1335,
	FEM8 = 1336,
	HELECOPT = 1346,
	FETUSJIB = 1347,
	HOLODUKE = 1348,
	SPACEMARINE = 1353,
	INDY = 1355,
	FETUS = 1358,
	FETUSBROKE = 1359,
	MONK = 1352,
	LUKE = 1354,
	COOLEXPLOSION1 = 1360,
	WATERSPLASH2 = 1380,
	FIREVASE = 1390,
	SCRATCH = 1393,
	FEM7 = 1395,
	APLAYERTOP = 1400,
	DUKE_APLAYER = 1405,
	PLAYERONWATER = 1420,
	DUKELYINGDEAD = 1518,
	DUKETORSO = 1520,
	DUKEGUN = 1528,
	DUKELEG = 1536,
	SHARK = 1550,
	BLOOD = 1620,
	FIRELASER = 1625,
	TRANSPORTERSTAR = 1630,
	SPIT = 1636,
	LOOGIE = 1637,
	FIST = 1640,
	FREEZEBLAST = 1641,
	DEVISTATORBLAST = 1642,
	SHRINKSPARK = 1646,
	TONGUE = 1647,
	MORTER = 1650,
	SHRINKEREXPLOSION = 1656,
	RADIUSEXPLOSION = 1670,
	FORCERIPPLE = 1671,
	LIZTROOP = 1680,
	LIZTROOPRUNNING = 1681,
	LIZTROOPSTAYPUT = 1682,
	LIZTOP = 1705,
	LIZTROOPSHOOT = 1715,
	LIZTROOPJETPACK = 1725,
	LIZTROOPDSPRITE = 1734,
	LIZTROOPONTOILET = 1741,
	LIZTROOPJUSTSIT = 1742,
	LIZTROOPDUCKING = 1744,
	HEADJIB1 = 1768,
	ARMJIB1 = 1772,
	LEGJIB1 = 1776,
	CANNONBALL = 1817,
	OCTABRAIN = 1820,
	OCTABRAINSTAYPUT = 1821,
	OCTATOP = 1845,
	OCTADEADSPRITE = 1855,
	INNERJAW = 1860,
	DRONE = 1880,
	EXPLOSION2 = 1890,
	COMMANDER = 1920,
	COMMANDERSTAYPUT = 1921,
	RECON = 1960,
	TANK = 1975,
	PIGCOP = 2000,
	PIGCOPSTAYPUT = 2001,
	PIGCOPDIVE = 2045,
	PIGCOPDEADSPRITE = 2060,
	PIGTOP = 2061,
	LIZMAN = 2120,
	LIZMANSTAYPUT = 2121,
	LIZMANSPITTING = 2150,
	LIZMANFEEDING = 2160,
	LIZMANJUMP = 2165,
	LIZMANDEADSPRITE = 2185,
	FECES = 2200,
	LIZMANHEAD1 = 2201,
	LIZMANARM1 = 2205,
	LIZMANLEG1 = 2209,
	EXPLOSION2BOT = 2219,
	USERWEAPON = 2235,
	HEADERBAR = 2242,
	JIBS1 = 2245,
	JIBS2 = 2250,
	JIBS3 = 2255,
	JIBS4 = 2260,
	JIBS5 = 2265,
	BURNING = 2270,
	FIRE = 2271,
	JIBS6 = 2286,
	BLOODSPLAT1 = 2296,
	BLOODSPLAT3 = 2297,
	BLOODSPLAT2 = 2298,
	BLOODSPLAT4 = 2299,
	OOZ = 2300,
	OOZ2 = 2309,
	WALLBLOOD1 = 2301,
	WALLBLOOD2 = 2302,
	WALLBLOOD3 = 2303,
	WALLBLOOD4 = 2304,
	WALLBLOOD5 = 2305,
	WALLBLOOD6 = 2306,
	WALLBLOOD7 = 2307,
	WALLBLOOD8 = 2308,
	BURNING2 = 2310,
	FIRE2 = 2311,
	CRACKKNUCKLES = 2324,
	SMALLSMOKE = 2329,
	SMALLSMOKEMAKER = 2330,
	FLOORFLAME = 2333,
	ROTATEGUN = 2360,
	GREENSLIME = 2370,
	WATERDRIPSPLASH = 2380,
	SCRAP6 = 2390,
	SCRAP1 = 2400,
	SCRAP2 = 2404,
	SCRAP3 = 2408,
	SCRAP4 = 2412,
	SCRAP5 = 2416,
	ORGANTIC = 2420,
	BETAVERSION = 2440,
	PLAYERISHERE = 2442,
	PLAYERWASHERE = 2443,
	SELECTDIR = 2444,
	F1HELP = 2445,
	NOTCHON = 2446,
	NOTCHOFF = 2447,
	GROWSPARK = 2448,
	DUKEICON = 2452,
	BADGUYICON = 2453,
	FOODICON = 2454,
	GETICON = 2455,
	MENUSCREEN = 2456,
	MENUBAR = 2457,
	KILLSICON = 2458,
	FIRSTAID_ICON = 2460,
	HEAT_ICON = 2461,
	BOTTOMSTATUSBAR = 2462,
	BOOT_ICON = 2463,
	FRAGBAR = 2465,
	JETPACK_ICON = 2467,
	AIRTANK_ICON = 2468,
	STEROIDS_ICON = 2469,
	HOLODUKE_ICON = 2470,
	ACCESS_ICON = 2471,
	DIGITALNUM = 2472,
	DUKECAR = 2491,
	CAMCORNER = 2482,
	CAMLIGHT = 2484,
	LOGO = 2485,
	TITLE = 2486,
	NUKEWARNINGICON = 2487,
	MOUSECURSOR = 2488,
	SLIDEBAR = 2489,
	DREALMS = 2492,
	BETASCREEN = 2493,
	WINDOWBORDER1 = 2494,
	TEXTBOX = 2495,
	WINDOWBORDER2 = 2496,
	DUKENUKEM = 2497,
	THREEDEE = 2498,
	INGAMEDUKETHREEDEE = 2499,
	TENSCREEN = 2500,
	PLUTOPAKSPRITE = 2501,
	DEVISTATOR = 2510,
	KNEE = 2521,
	CROSSHAIR = 2523,
	FIRSTGUN = 2524,
	FIRSTGUNRELOAD = 2528,
	FALLINGCLIP = 2530,
	CLIPINHAND = 2531,
	HAND = 2532,
	SHELL = 2533,
	SHOTGUNSHELL = 2535,
	CHAINGUN = 2536,
	RPGGUN = 2544,
	RPGMUZZLEFLASH = 2545,
	FREEZE = 2548,
	CATLITE = 2552,
	SHRINKER = 2556,
	HANDHOLDINGLASER = 2563,
	TRIPBOMB = 2566,
	LASERLINE = 2567,
	HANDHOLDINGACCESS = 2568,
	HANDREMOTE = 2570,
	HANDTHROW = 2573,
	TIP = 2576,
	GLAIR = 2578,
	SCUBAMASK = 2581,
	SPACEMASK = 2584,
	FORCESPHERE = 2590,
	SHOTSPARK1 = 2595,
	RPG = 2605,
	LASERSITE = 2612,
	SHOTGUN = 2613,
	BOSS1 = 2630,
	BOSS1STAYPUT = 2631,
	BOSS1SHOOT = 2660,
	BOSS1LOB = 2670,
	BOSSTOP = 2696,
	BOSS2 = 2710,
	BOSS3 = 2760,
	SPINNINGNUKEICON = 2813,
	BIGFNTCURSOR = 2820,
	SMALLFNTCURSOR = 2821,
	STARTALPHANUM = 2822,
	ENDALPHANUM = 2915,
	BIGALPHANUM = 2940,
	BIGPERIOD = 3002,
	BIGCOMMA = 3003,
	BIGX = 3004,
	BIGQ = 3005,
	BIGSEMI = 3006,
	BIGCOLIN = 3007,
	THREEBYFIVE = 3010,
	BIGAPPOS = 3022,
	BLANK = 3026,
	MINIFONT = 3072,
	BUTTON1 = 3164,
	GLASS3 = 3187,
	RESPAWNMARKERRED = 3190,
	RESPAWNMARKERYELLOW = 3200,
	RESPAWNMARKERGREEN = 3210,
	BONUSSCREEN = 3240,
	VIEWBORDER = 3250,
	VICTORY1 = 3260,
	ORDERING = 3270,
	TEXTSTORY = 3280,
	LOADSCREEN = 3281,
	BORNTOBEWILDSCREEN = 3370,
	BLIMP = 3400,
	FEM9 = 3450,
	FOOTPRINT = 3701,
	POOP = 4094,
	FRAMEEFFECT1 = 4095,
	PANNEL3 = 4099,
	SCREENBREAK14 = 4120,
	SCREENBREAK15 = 4123,
	SCREENBREAK19 = 4125,
	SCREENBREAK16 = 4127,
	SCREENBREAK17 = 4128,
	SCREENBREAK18 = 4129,
	W_TECHWALL11 = 4130,
	W_TECHWALL12 = 4131,
	W_TECHWALL13 = 4132,
	W_TECHWALL14 = 4133,
	W_TECHWALL5 = 4134,
	W_TECHWALL6 = 4136,
	W_TECHWALL7 = 4138,
	W_TECHWALL8 = 4140,
	W_TECHWALL9 = 4142,
	BPANNEL3 = 4100,
	W_HITTECHWALL16 = 4144,
	W_HITTECHWALL10 = 4145,
	W_HITTECHWALL15 = 4147,
	W_MILKSHELF = 4181,
	W_MILKSHELFBROKE = 4203,
	PURPLELAVA = 4240,
	LAVABUBBLE = 4340,
	DUKECUTOUT = 4352,
	TARGET = 4359,
	GUNPOWDERBARREL = 4360,
	DUCK = 4361,
	HATRACK = 4367,
	DESKLAMP = 4370,
	COFFEEMACHINE = 4372,
	CUPS = 4373,
	GAVALS = 4374,
	GAVALS2 = 4375,
	POLICELIGHTPOLE = 4377,
	FLOORBASKET = 4388,
	PUKE = 4389,
	DOORTILE23 = 4391,
	TOPSECRET = 4396,
	SPEAKER = 4397,
	TEDDYBEAR = 4400,
	ROBOTDOG = 4402,
	ROBOTPIRATE = 4404,
	ROBOTMOUSE = 4407,
	MAIL = 4410,
	MAILBAG = 4413,
	HOTMEAT = 4427,
	COFFEEMUG = 4438,
	DONUTS2 = 4440,
	TRIPODCAMERA = 4444,
	METER = 4453,
	DESKPHONE = 4454,
	GUMBALLMACHINE = 4458,
	GUMBALLMACHINEBROKE = 4459,
	PAPER = 4460,
	MACE = 4464,
	GENERICPOLE2 = 4465,
	XXXSTACY = 4470,
	WETFLOOR = 4495,
	BROOM = 4496,
	MOP = 4497,
	LETTER = 4502,
	PIRATE1A = 4510,
	PIRATE4A = 4511,
	PIRATE2A = 4512,
	PIRATE5A = 4513,
	PIRATE3A = 4514,
	PIRATE6A = 4515,
	PIRATEHALF = 4516,
	CHESTOFGOLD = 4520,
	SIDEBOLT1 = 4525,
	FOODOBJECT1 = 4530,
	FOODOBJECT2 = 4531,
	FOODOBJECT3 = 4532,
	FOODOBJECT4 = 4533,
	FOODOBJECT5 = 4534,
	FOODOBJECT6 = 4535,
	FOODOBJECT7 = 4536,
	FOODOBJECT8 = 4537,
	FOODOBJECT9 = 4538,
	FOODOBJECT10 = 4539,
	FOODOBJECT11 = 4540,
	FOODOBJECT12 = 4541,
	FOODOBJECT13 = 4542,
	FOODOBJECT14 = 4543,
	FOODOBJECT15 = 4544,
	FOODOBJECT16 = 4545,
	FOODOBJECT17 = 4546,
	FOODOBJECT18 = 4547,
	FOODOBJECT19 = 4548,
	FOODOBJECT20 = 4549,
	HEADLAMP = 4550,
	TAMPON = 4557,
	SKINNEDCHICKEN = 4554,
	FEATHEREDCHICKEN = 4555,
	ROBOTDOG2 = 4560,
	JOLLYMEAL = 4569,
	DUKEBURGER = 4570,
	SHOPPINGCART = 4576,
	CANWITHSOMETHING2 = 4580,
	CANWITHSOMETHING3 = 4581,
	CANWITHSOMETHING4 = 4582,
	SNAKEP = 4590,
	DOLPHIN1 = 4591,
	DOLPHIN2 = 4592,
	NEWBEAST = 4610,
	NEWBEASTSTAYPUT = 4611,
	NEWBEASTJUMP = 4690,
	NEWBEASTHANG = 4670,
	NEWBEASTHANGDEAD = 4671,
	BOSS4 = 4740,
	BOSS4STAYPUT = 4741,
	FEM10 = 4864,
	TOUGHGAL = 4866,
	MAN = 4871,
	MAN2 = 4872,
	WOMAN = 4874,
	PLEASEWAIT = 4887,
	NATURALLIGHTNING = 4890,
	WEATHERWARN = 4893,
	DUKETAG = 4900,
	SIGN1 = 4909,
	SIGN2 = 4912,
	JURYGUY = 4943,

	// New names from World Tour
	FLAMETHROWERSPRITE = 5134,
	FLAMETHROWERAMMO = 5135,
	FLAMETHROWER = 5138,
	ONFIRE = 5152,
	LAVAPOOL = 5304,
	LAVAPOOLBUBBLE = 5207,
	WHISPYSMOKE = 5268,
	FLAMETHROWERFIRE = 5139,
	FLAMETHROWERFLAME = 1891,
	FLAMETHROWERPILOT = 5174,
	FIREBALL = 5163,
	BURNEDCORPSE = 5173,
	FIREFLY = 5180,
	FIREFLYSHRINKEFFECT = 5360,
	FIREFLYGROWEFFECT = 5367,
	FIREFLYFLYINGEFFECT = 5296,
	DEVELOPERCOMMENTARY = 5294,
	BOSS5 = 5310,
	BOSS5STAYPUT = 5311,

	// Redneck Rampage

	RR_GRID = 0,
	RR_JAILDOOR = 11,
	RR_LNRDTAG = 15,
	RR_SIGN1 = 16,
	RR_SIGN2 = 17,
	RR_TORCH = 18,
	//FIRSTGUNSPRITE = 21,
	RR_RIFLESPRITE = 22,
	RR_CROSSBOWSPRITE = 23,
	RR_TEATGUN = 24,
	RR_BUZSAWSPRITE = 25,
	RR_DYNAMITE = 26,
	RR_POWDERKEGSPRITE = 27,
	//SHOTGUNSPRITE = 28,
	RR_ALIENARMGUN = 29,
	//HEALTHBOX = 30,
	//AMMOBOX = 31,
	RR_TEATAMMO = 32,
	//INVENTORYBOX = 33,
	RR_DOORKEYS = 34,
	RR_LIGHTNIN = 35,
	RR_DESTRUCTO = 36,
	RR_JAILSOUND = 38,
	//AMMO = 40,
	RR_RIFLEAMMO = 41,
	RR_ALIENBLASTERAMMO = 42,
	RR_BLADEAMMO = 43,
	//HBOMBAMMO = 47,
	//SHOTGUNAMMO = 49,
	RR_BEER = 51,
	RR_PORKBALLS = 52,
	RR_WHISKEY = 53,
	RR_MOONSHINE = 55,
	RR_SNORKLE = 56,
	RR_COWPIE = 57,
	RR_DOORKEY = 60,
	//BOOTS = 61,
	RR_MINECARTKILLER = 67,
	RR_SHADESECTOR = 68,
	RR_SOUNDFX = 71,
	RR_MULTISWITCH = 98,
	RR_DOORSHOCK = 120,
	RR_FLOORSLIME = 132,
	RR_BIGFORCE = 135,
	RR_SCREENBREAK6 = 164,
	RR_SCREENBREAK7 = 165,
	RR_SCREENBREAK8 = 166,
	RR_FANSPRITEWORK = 210,
	RR_FANSPRITE = 211,
	RR_FANSPRITEBROKE = 215,
	RR_GRATE1 = 234,
	RR_BGRATE1 = 235,
	RR_WATERDRIP = 239,
	RR_WATERBUBBLE = 240,
	RR_WATERBUBBLEMAKER = 241,
	RR_W_FORCEFIELD = 242,
	RR_LIGHTSWITCH2 = 250,
	RR_UFOBEAM = 252,
	RR_BOULDER = 256,
	RR_BOULDER1 = 264,
	RR_BOWLLINE = 280,
	RR_CHICKENA = 285,
	RR_CHICKENC = 286,
	RR_HEADCHK = 287,
	RR_FEATHERCHK = 288,
	RR_LOAF = 289,
	RR_NUGGETS = 290,
	RR_PACKEDCHK = 291,
	RR_BONELESSCHK = 292,
	RR_JIBSCHK = 293,
	RR_BIGFNTCURSOR = 512,
	RR_SMALLFNTCURSOR = 513,
	RR_STARTALPHANUM = 514,
	RR_ENDALPHANUM = 607,
	RR_BIGALPHANUM = 632,
	RR_BIGPERIOD = 694,
	RR_BIGCOMMA = 695,
	RR_BIGX = 696,
	RR_BIGQ = 697,
	RR_BIGSEMI = 698,
	RR_BIGCOLIN = 699,
	RR_THREEBYFIVE = 702,
	RR_BIGAPPOS = 714,
	RR_MINIFONT = 718,
	RR_RESPAWNMARKERRED = 866,

	RR_MOONSKY1 = 1022,
	RR_MOONSKY2 = 1023,
	RR_MOONSKY3 = 1024,
	RR_MOONSKY4 = 1025,
	RR_BIGORBIT1 = 1026,
	RR_BIGORBIT2 = 1027,
	RR_BIGORBIT3 = 1028,
	RR_BIGORBIT4 = 1029,
	RR_BIGORBIT5 =1030,
	RR_WATERTILE2 = 1045,
	RR_GLASS = 1056,
	RR_GLASS2 = 1057,
	RR_CRACK1 = 1075,
	RR_CRACK2 = 1076,
	RR_CRACK3 = 1077,
	RR_CRACK4 = 1078,
	RR_FOOTPRINTS = 1079,
	RR_MIRROR = 1089,
	RR_WATERFOUNTAIN = 1092,
	RR_REACTOR = 1107,
	RR_REACTORBURNT = 1108,
	RR_REACTORSPARK = 1109,
	RR_BOLT1 = 1127,
	
	
	RR_CAMERA1 = 1134,
	RR_FOOTPRINTS2 = 1144,
	RR_FOOTPRINTS3 = 1145,
	RR_FOOTPRINTS4 = 1146,
	RR_SLIME = 1161,
	RR_QUEBALL = 1184,
	RR_STRIPEBALL = 1185,
	RR_POCKET = 1186,
	RR_AFLAM1191 = 1191,
	RR_AFLAM1193 = 1193,
	RR_NEON1 = 1200,
	RR_NEON2 = 1201,
	RR_BOUNCEMINE = 1204,
	RR_BULLETHOLE = 1212,
	RR_TIRE = 1230,
	RR_NEON3 = 1241,
	RR_NEON4 = 1242,
	RR_NEON5 = 1243,
	RR_GLASSPIECES = 1256,
	RR_NEON6 = 1264,
	RR_OOZFILTER = 1273,
	RR_FLOORPLASMA = 1276,
	RR_BOTTLE12 = 1282,
	RR_BOTTLE13 = 1283,
	RR_BOTTLE14 = 1284,
	RR_BOTTLE15 = 1285,
	RR_BOTTLE16 = 1286,
	RR_BOTTLE17 = 1287,
	RR_BOTTLE18 = 1288,
	RR_VENDMACHINE = 1291,
	RR_VENDMACHINEBROKE = 1293,
	RR_COLAMACHINE = 1294,
	RR_COLAMACHINEBROKE = 1296,
	RR_CRANE = 1299,
	RR_BLOODPOOL = 1303,
	RR_CANWITHSOMETHING = 1309,
	RR_FEATHERS = 1310,
	RR_BANNER = 1313,
	RR_SEENINE = 1324,
	RR_SEENINEDEAD = 1325,
	RR_STEAM = 1327,
	RR_CEILINGSTEAM = 1332,
	RR_TRANSPORTERBEAM = 1338,
	RR_RAT = 1344,
	RR_TRASH = 1346,
	RR_WATERSPLASH2 = 1383,
	RR_BLOOD = 1391,
	RR_TRANSPORTERSTAR = 1398,
	RR_ALIENBLAST = 1409,
	RR_TONGUE = 1414,
	RR_MORTER = 1416,
	RR_MUD = 1420,
	RR_RADIUSEXPLOSION = 1426,
	RR_FORCERIPPLE = 1427,
	RR_INNERJAW = 1439,
	RR_EXPLOSION2 = 1441,
	RR_EXPLOSION3 = 1442,
	RR_JIBS1 = 1463,
	RR_JIBS2 = 1468,
	RR_JIBS3 = 1473,
	RR_JIBS4 = 1478,
	RR_JIBS5 = 1483,
	RR_BURNING = 1494,
	RR_FIRE = 1495,
	RR_JIBS6 = 1515,
	RR_BLOODSPLAT1 = 1525,
	RR_BLOODSPLAT3 = 1526,
	RR_BLOODSPLAT2 = 1527,
	RR_BLOODSPLAT4 = 1528,
	RR_OOZ = 1529,
	RR_WALLBLOOD1 = 1530,
	RR_WALLBLOOD2 = 1531,
	RR_WALLBLOOD3 = 1532,
	RR_WALLBLOOD4 = 1533,
	RR_WALLBLOOD5 = 1534,
	RR_WALLBLOOD6 = 1535,
	RR_WALLBLOOD7 = 1536,
	RR_WALLBLOOD8 = 1537,
	RR_OOZ2 = 1538,
	RR_BURNING2 = 1539,
	RR_FIRE2 = 1540,
	RR_SMALLSMOKE = 1554,
	RR_SMALLSMOKEMAKER = 1555,
	RR_SCRAP6 = 1595,
	RR_SCRAP1 = 1605,
	RR_SCRAP2 = 1609,
	RR_SCRAP3 = 1613,
	RR_SCRAP4 = 1617,
	RR_SCRAP5 = 1621,
	RR_F1HELP = 1633,
	RR_MENUSCREEN = 1641,
	RR_MENUBAR = 1642,
	RR_KILLSICON = 1643,
	RR_WHISHKEY_ICON = 1645,
	RR_EMPTY_ICON = 1646,
	RR_BOTTOMSTATUSBAR = 1647,
	RR_BOOT_ICON = 1648,
	RR_FRAGBAR = 1650,
	RR_COWPIE_ICON = 1652,
	RR_SNORKLE_ICON = 1653,
	RR_MOONSHINE_ICON = 1654,
	RR_BEER_ICON = 1655,
	RR_ACCESS_ICON = 1656,
	RR_DIGITALNUM = 1657,
	RR_SLIDEBAR = 1674,
	RR_WINDOWBORDER1 = 1679,
	RR_TEXTBOX = 1680,
	RR_WINDOWBORDER2 = 1681,
	RR_INGAMELNRDTHREEDEE = 1684,
	RR_TENSCREEN = 1685,
	RR_NEWCROSSHAIR = 1689,
	RR_CROSSHAIR = 1692,
	RR_SHELL = 1702,
	RR_SHOTGUNSHELL = 1704,
	RR_FORCESPHERE = 1759,
	RR_SHOTSPARK1 = 1764,
	RR_CROSSBOW = 1774,
	RR_TORNADO = 1930,
	RR_TIKILAMP = 1990,
	RR_POPCORN = 2021,
	RR_TESLACON = 2056,
	RR_TESLABALL = 2094,
	RR_DILDO = 2095,
	RR_TESLA = 2097,
	RR_HURTRAIL = 2221,
	RR_LOCKSWITCH1 = 2224,
	RR_STATUEFLASH = 2231,
	RR_REACTOR2 = 2239,
	RR_REACTOR2SPARK = 2243,
	RR_REACTOR2BURNT = 2247,
	RR_EXPLOSION2BOT = 2272,
	RR_SELECTDIR = 2444,
	RR_VIEWBORDER = 2520,
	RR_ORDERING = 2531,
	RR_TEXTSTORY = 2541,
	RR_LOADSCREEN = 2542,
	RR_STARSKY2 = 2577,
	RR_SPINNINGNUKEICON = 896,
	RR_TOILETPAPER = 2864,
	RR_BUSTAWIN5A = 2878,
	RR_BUSTAWIN5B = 2879,
	RR_BUSTAWIN4A = 2898,
	RR_BUSTAWIN4B = 2899,
	RR_FRAMEEFFECT1 = 2999,

	RR_AFLAM3062 = 3062,
	
	RR_LOAFTILE = 3120,
	RR_NUGGETTILE = 3122,
	RR_BROASTEDTILE = 3123,
	RR_BONELESSTILE = 3124,
	RR_HEAD1TILE = 3132,
	RR_HEAD2TILE = 3133,
	RR_CHICKENATILE = 3190,
	RR_CHICKENBTILE = 3191,
	RR_CHICKENCTILE = 3192,
	
	RR_NEWPISTOL = 3328,
	RR_NEWPISTOLCOCK = 3336,
	RR_NEWCROWBAR = 3340,
	RR_CROWBAR = RR_NEWCROWBAR,
	RR_NEWSHOTGUN = 3350,
	RR_SHOTGUN = RR_NEWSHOTGUN,
	RR_NEWDYNAMITE = 3360,
	RR_RIFLE = 3380,
	RR_CIRCLESTUCK = 3388,
	RR_SHITBALL = 3390,
	RR_BUZSAW = 3395,
	RR_CIRCLESAW = 3400,
	RR_LUMBERBLADE = 3411,
	RR_FIRELASER = 3420,
	RR_BOWLINGBALL = 3430,
	RR_BOWLINGBALLSPRITE = 3437,
	RR_CHEERBOMB = -3464,
	RR_OWHIP = 3471,
	RR_UWHIP = 3475,
	RR_BACKGROUND = 3822,
	RR_APLAYERTOP = 3840,
	RR_APLAYER = 3845,
	RR_PLAYERONWATER = 3860,
	RR_LNYDLADDER = 3975,
	RR_LNRDLYINGDEAD = 3998,
	RR_LNRDGUN = 4041,
	RR_LNRDTORSO = 4046,
	RR_LNRLEG = 4055,
	RR_DOGATTACK = 4060,
	RR_BILLYWALK = 4096,
	RR_BILLYDIE = 4137,
	RR_BILLYCOCK = 4147,
	RR_BILLYRAY = 4162,
	RR_BILLYSHOOT = 4162,
	RR_BILLYRAYSTAYPUT = 4163,
	RR_BILLYBUT = 4188,
	RR_BILLYSCRATCH = 4191,
	RR_BILLYSNIFF = 4195,
	RR_BILLYWOUND = 4202,
	RR_BILLYGORE = 4228,
	RR_BILLYJIBA = 4235,
	RR_BILLYJIBB = 4244,
	RR_DOGRUN = 4260,
	RR_DOGDIE = 4295,
	RR_DOGDEAD = 4303,
	RR_DOGBARK = 4305,
	RR_LTH = 4352,
	RR_LTHSTRAFE = 4395,
	RR_LTHLOAD = 4430,
	RR_LTHDIE = 4456,
	RR_BUBBASCRATCH = 4464,
	RR_BUBBANOSE = 4476,
	RR_BUBBAPISS = 4487,
	RR_BUBBASTAND = 4504,
	RR_BUBBAOUCH = 4506,
	RR_BUBBADIE = 4513,
	RR_BUBBADEAD = 4523,
	RR_HULK = 4649,
	RR_HULKSTAYPUT = 4650,
	RR_HULKA = 4651,
	RR_HULKB = 4652,
	RR_HULKC = 4653,
	RR_HULKJIBA = 4748,
	RR_HULKJIBB = 4753,
	RR_HULKJIBC = 4758,
	RR_SBSWIPE = 4770,
	RR_SBPAIN = 4810,
	RR_SBDIE = 4820,
	RR_HEN = 4861,
	RR_HENSTAYPUT = 4862,
	RR_HENSTAND = 4897,
	RR_MOSQUITO = 4916,
	RR_PIG = 4945,
	RR_PIGSTAYPUT = 4946,
	RR_PIGEAT = 4983,
	RR_SBMOVE = 5015,
	RR_SBSPIT = 5050,
	RR_SBDIP = 5085,
	RR_MINION = 5120,
	RR_MINIONSTAYPUT = 5121,
	RR_UFO1 = 5270,
	RR_UFO2 = 5274,
	RR_UFO3 = 5278,
	RR_UFO4 = 5282,
	RR_UFO5 = 5286,
	RR_MINJIBA = 5290,
	RR_MINJIBB = 5295,
	RR_MINJIBC = 5300,
	RR_COW = 5317,
	RR_COOT = 5376,
	RR_COOTSTAYPUT = 5377,
	RR_COOTSHOOT = 5411,
	RR_COOTDIE = 5437,
	RR_COOTDUCK = 5481,
	RR_COOTPAIN = 5548,
	RR_COOTTRANS = 5568,
	RR_COOTGETUP = 5579,
	RR_ECLAIRHEALTH = 5595,
	RR_COOTJIBA = 5602,
	RR_COOTJIBB = 5607,
	RR_COOTJIBC = 5616,
	RR_VIXEN = 5635,
	RR_VIXENPAIN = 5675,
	RR_VIXENDIE = 5710,
	RR_VIXENSHOOT = 5720,
	RR_VIXENWDN = 5740,
	RR_VIXENWUP = 5775,
	RR_VIXENKICK = 5805,
	RR_VIXENTELE = 5845,
	RR_VIXENTEAT = 5851,
	RR_BIKERBV = 5891,
	RR_MAKEOUT = 6225,
	RR_CHEER = 6658,
	RR_CHEERSTAYPUT = 6659,
	//RA
	RR_AIRPLANE = 8450,
	RR_SWAMPBUGGY = 7233,
	RR_MOTORCYCLE = 7220,
	RR_CHIKENCROSSBOW = 1781,
	RR_BIKERSTAND = 5995,
	RR_BIKERRIDE = 5890,
	RR_BIKERRIDEDAISY = 6401,
	RR_MINIONAIRBOAT = 7192,
	RR_HULKAIRBOAT = 7199,
	RR_DAISYMAE = 6658,
	RR_DAISYAIRBOAT = 7206,
	RR_MINIONUFO = 5260,
	RR_JACKOLOPE = 7280,
	RR_BANJOCOOTER = 7030,
	RR_GUITARBILLY = 7035,
	RR_MAMACLOUD = 8663,
	RR_MAMAJACKOLOPE = 8705,


	// Stuff that gets referenced but has no name. RR Reconstruction only has Duke names for these items which should be avoided.
	RR_1251 = 1251,
	RR_1268 = 1268,
	RR_1187 = 1187,
	RR_1304 = 1304,
	RR_1305 = 1305,
	RR_1306 = 1306,
	RR_1309 = 1309,
	RR_1315 = 1315,
	RR_1317 = 1317,
	RR_1388 = 1388,
	RR_3440 = 3440,


};

extern int APLAYER;
extern int CAMERA1;
END_DUKE_NS
