#define nsHtml5NamedCharacters_cpp__
#include "prtypes.h"
#include "jArray.h"
#include "nscore.h"
#include "nsDebug.h"
#include "prlog.h"
#include "nsMemory.h"

#include "nsHtml5NamedCharacters.h"

jArray<jArray<PRInt8,PRInt32>,PRInt32> nsHtml5NamedCharacters::NAMES;

const PRUnichar nsHtml5NamedCharacters::VALUES[][2] = {
#define NAMED_CHARACTER_REFERENCE(N, CHARS, LEN, FLAG, VALUE) \
{ VALUE },
#include "nsHtml5NamedCharactersInclude.h"
#undef NAMED_CHARACTER_REFERENCE
{0, 0} };

PRUnichar** nsHtml5NamedCharacters::WINDOWS_1252;
static PRUnichar const WINDOWS_1252_DATA[] = {
  0x20AC,
  0x0081,
  0x201A,
  0x0192,
  0x201E,
  0x2026,
  0x2020,
  0x2021,
  0x02C6,
  0x2030,
  0x0160,
  0x2039,
  0x0152,
  0x008D,
  0x017D,
  0x008F,
  0x0090,
  0x2018,
  0x2019,
  0x201C,
  0x201D,
  0x2022,
  0x2013,
  0x2014,
  0x02DC,
  0x2122,
  0x0161,
  0x203A,
  0x0153,
  0x009D,
  0x017E,
  0x0178
};

static PRInt32 const HILO_ACCEL_65[] = {
0, 0, 0, 0, 0, 0, 0, 12386493, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38863441, 0, 0, 0, 0, 58524541, 0, 0, 0, 73466977, 0, 0, 0, 80282823, 0, 0, 0, 0, 0, 109971084, 0, 0, 130549704, 133957628, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_66[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27525540, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80348362, 0, 0, 0, 0, 0, 110036623, 0, 0, 0, 134088701, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_68[] = {
0, 0, 0, 4980811, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37159479, 0, 0, 0, 0, 0, 0, 0, 0, 62915519, 0, 0, 0, 0, 0, 0, 0, 89982301, 0, 0, 0, 0, 0, 0, 0, 0, 134154239, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_69[] = {
65536, 0, 0, 0, 0, 0, 0, 0, 13172937, 0, 0, 0, 0, 0, 24052079, 0, 0, 27656613, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 69796904, 0, 0, 0, 0, 80479435, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_72[] = {
0, 0, 2555943, 0, 0, 0, 0, 0, 0, 0, 15532269, 0, 0, 0, 0, 0, 0, 0, 30540241, 33161721, 0, 0, 0, 0, 0, 39584348, 0, 0, 0, 58590078, 0, 0, 0, 0, 0, 0, 0, 80544973, 0, 0, 0, 0, 0, 110102160, 0, 0, 130615241, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_73[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38928978, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_74[] = {
0, 0, 0, 5046349, 0, 0, 10944679, 0, 13238474, 0, 15597806, 16056565, 0, 20578618, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_76[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 92669317, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_77[] = {
196610, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_78[] = {
0, 0, 0, 0, 8454273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44696234, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_79[] = {
0, 0, 2687016, 0, 0, 0, 0, 0, 13304011, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30605779, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_82[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33227259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 92734855, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_83[] = {
0, 0, 0, 5111886, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33358332, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100599295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_84[] = {
0, 0, 0, 0, 8585346, 0, 11075752, 0, 0, 0, 0, 16187638, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_85[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27263391, 0, 0, 0, 0, 0, 0, 0, 38994515, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_86[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 92865928, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_90[] = {
0, 0, 0, 5177423, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_97[] = {
327684, 1900571, 2949162, 5374032, 8716420, 0, 11206826, 12517566, 13435084, 0, 15663343, 16515320, 19988785, 20644155, 24183152, 25952652, 0, 27918759, 30671316, 33489406, 34734607, 0, 0, 0, 39125588, 39649885, 40305254, 45220523, 52691740, 58917759, 63112129, 67240962, 70059050, 73925730, 75367549, 0, 79561917, 81986766, 90703198, 93390218, 100795904, 104990268, 0, 111675025, 116590323, 126814094, 130811850, 135006208, 0, 0, 138479679, 139266125
};

static PRInt32 const HILO_ACCEL_98[] = {
393222, 0, 0, 0, 0, 0, 11272364, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34865683, 37225016, 0, 0, 0, 0, 40370792, 45351603, 0, 59048836, 0, 0, 70124590, 73991273, 0, 0, 0, 82445540, 0, 93521298, 0, 0, 0, 112133801, 116655860, 126879632, 130942925, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_99[] = {
589831, 1966110, 3276846, 5505107, 8978566, 10420383, 11468973, 12583104, 13631694, 15139046, 15794416, 16711933, 20054322, 20840764, 24379762, 26018189, 0, 28115371, 30998997, 33686016, 35062293, 37290553, 38273608, 0, 39256662, 39780958, 40829545, 45482677, 53150501, 59179910, 63505348, 67306499, 70255663, 74056810, 75629695, 79037621, 79692991, 82773227, 90834281, 93914516, 101058051, 105055811, 0, 112461488, 117573365, 127076241, 131139535, 135071757, 136054812, 136906791, 138610754, 139397198
};

static PRInt32 const HILO_ACCEL_100[] = {
0, 0, 3342387, 0, 9044106, 0, 11534512, 0, 13697233, 0, 0, 0, 0, 0, 24445301, 0, 0, 0, 0, 0, 35127832, 37421626, 0, 0, 0, 39846496, 0, 45548215, 53216044, 59442056, 63570890, 0, 70321201, 0, 0, 0, 0, 83166448, 90899819, 93980058, 101385735, 0, 0, 112789173, 117769987, 127141780, 131336146, 135137294, 0, 136972330, 0, 139462736
};

static PRInt32 const HILO_ACCEL_101[] = {
0, 2162719, 3473460, 5636181, 0, 0, 0, 0, 0, 0, 0, 18809088, 20185395, 21299519, 0, 0, 0, 28377518, 0, 0, 0, 37945916, 38339145, 0, 0, 39977569, 40960624, 46072504, 53609261, 59704204, 63636427, 67372036, 71042098, 74318955, 75826307, 0, 0, 84935926, 90965356, 94569883, 101451276, 105383492, 0, 113247930, 118490886, 127207317, 0, 135530511, 136316957, 0, 138741828, 139593809
};

static PRInt32 const HILO_ACCEL_102[] = {
655370, 2228258, 3538998, 5701719, 9109643, 10485920, 11600049, 12648641, 13762770, 15204584, 15859954, 18874656, 20250933, 21365062, 24510838, 26083726, 27328929, 28443058, 31064538, 33751555, 35193369, 38011460, 38404682, 38601293, 39322200, 40043107, 41091698, 46138048, 53674803, 59835280, 63767500, 67634181, 71107645, 74384495, 75957382, 79103159, 79758529, 85132561, 91030893, 94635428, 101582349, 105449033, 109119105, 113444545, 118621969, 127272854, 131467221, 135596053, 136382497, 137037867, 138807366, 139659347
};

static PRInt32 const HILO_ACCEL_103[] = {
786443, 0, 0, 0, 9240716, 0, 11665586, 0, 13893843, 0, 0, 0, 0, 0, 24641911, 0, 0, 0, 0, 0, 35324442, 0, 0, 0, 0, 0, 41222772, 0, 0, 0, 64095182, 0, 71238718, 0, 76088456, 0, 79824066, 85263636, 0, 94963109, 101844495, 0, 0, 0, 0, 0, 131598295, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_104[] = {
0, 0, 3604535, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26149263, 0, 28508595, 31326683, 33948164, 0, 0, 0, 0, 0, 0, 0, 0, 53936948, 59966354, 0, 0, 0, 0, 0, 0, 79889603, 85525782, 91096430, 95159722, 101975571, 105711178, 0, 113772228, 119080723, 128059287, 131794905, 0, 0, 137168940, 0, 139724884
};

static PRInt32 const HILO_ACCEL_105[] = {
0, 0, 3866680, 6160472, 0, 10616993, 0, 12714178, 0, 0, 0, 0, 20316470, 0, 0, 26214800, 0, 30015924, 31392223, 34210311, 0, 0, 0, 38666830, 0, 0, 0, 46990017, 54919992, 60752788, 0, 67699721, 71304256, 0, 76416138, 0, 0, 0, 91817327, 95421869, 102041109, 105907790, 109184642, 114493129, 119998234, 128518051, 0, 0, 0, 137234478, 138872903, 139790421
};

static PRInt32 const HILO_ACCEL_106[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60818336, 0, 0, 71369793, 0, 76481679, 0, 79955140, 85591322, 0, 95487409, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_107[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 47055566, 0, 0, 0, 0, 0, 74515568, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_108[] = {
851981, 0, 4063292, 0, 9306254, 0, 0, 0, 0, 0, 0, 19005729, 0, 0, 0, 26280337, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41419382, 47776463, 55051079, 60949409, 64422867, 67896330, 71631938, 0, 0, 0, 0, 85919003, 91948410, 96273842, 102368790, 106825297, 0, 114689748, 120063784, 0, 132057052, 135661590, 0, 137365551, 0, 0
};

static PRInt32 const HILO_ACCEL_109[] = {
917518, 0, 0, 0, 9502863, 0, 0, 0, 14155989, 0, 0, 19071267, 0, 0, 24838521, 0, 0, 0, 31457760, 0, 35389980, 0, 0, 0, 0, 0, 41681529, 0, 0, 0, 64881624, 0, 0, 0, 76940432, 79168696, 0, 86115616, 0, 96339390, 102696475, 106890847, 0, 114820823, 120522537, 0, 132253664, 0, 0, 137431089, 0, 0
};

static PRInt32 const HILO_ACCEL_110[] = {
983055, 0, 0, 0, 0, 0, 0, 0, 14483673, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35783197, 0, 0, 0, 0, 0, 43188861, 47842010, 0, 0, 65012703, 67961869, 72090694, 0, 77661335, 0, 0, 86574371, 92013948, 0, 0, 0, 0, 114886361, 0, 0, 0, 0, 0, 137496626, 0, 0
};

static PRInt32 const HILO_ACCEL_111[] = {
1114128, 2293795, 4587583, 8257631, 9633938, 10813603, 11731123, 12845251, 14680286, 15270121, 15925491, 19661092, 20382007, 23724359, 24904060, 26411410, 27394466, 30147019, 31523297, 34275851, 35914275, 38076997, 38470219, 38732367, 39387737, 40108644, 43319956, 50987739, 56165193, 61801379, 65143777, 68224014, 72156237, 74908786, 77923490, 79234233, 80020677, 87754026, 92145021, 97060287, 102762016, 107152992, 109250179, 115345114, 120850224, 128976810, 132384739, 135727127, 136448034, 137758771, 138938440, 139855958
};

static PRInt32 const HILO_ACCEL_112[] = {
1179666, 0, 0, 0, 9699476, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25035133, 0, 0, 0, 0, 0, 36766245, 0, 0, 0, 0, 0, 43844246, 51053323, 0, 0, 65536995, 68289554, 0, 0, 77989030, 0, 0, 87885116, 92210559, 97453514, 102958625, 0, 109315716, 115541729, 121046837, 129042353, 132974565, 135792664, 136513571, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_113[] = {
0, 0, 0, 0, 9896085, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32047586, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66192361, 0, 0, 0, 78120103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 121964344, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_114[] = {
1310739, 2359332, 4653127, 0, 0, 0, 12189876, 0, 0, 0, 0, 0, 0, 0, 25100671, 27001236, 0, 30212557, 0, 34341388, 36831794, 0, 0, 0, 0, 0, 43975326, 51249932, 56296282, 61998000, 66323443, 69600275, 72221774, 0, 0, 0, 0, 88278334, 0, 97781200, 103810596, 108856932, 0, 115607268, 122029894, 130025394, 133302254, 135858201, 136644644, 137889847, 0, 0
};

static PRInt32 const HILO_ACCEL_115[] = {
1441813, 2424869, 4718664, 8388735, 10027160, 10879142, 12255419, 12976325, 14745825, 15401194, 15991028, 19857709, 20447544, 23789931, 25297280, 27132317, 27460003, 30343630, 32113130, 34472461, 36897331, 38142534, 38535756, 38797904, 39453274, 40174181, 44237472, 51708687, 56623964, 62260147, 66520053, 69665831, 72483919, 75105400, 78578857, 79365306, 80086214, 88933700, 92341632, 99026389, 104072753, 108988030, 109381253, 116000485, 122292039, 130287553, 133367795, 135923738, 136710182, 138020921, 139003977, 139921495
};

static PRInt32 const HILO_ACCEL_116[] = {
1572887, 0, 0, 0, 10092698, 0, 12320956, 0, 14811362, 0, 0, 19923248, 0, 23921004, 25493891, 0, 0, 0, 32178667, 0, 36962868, 0, 0, 0, 0, 0, 44368548, 0, 56689505, 62456759, 66716664, 0, 73401427, 0, 78709936, 0, 0, 89785678, 0, 99550696, 104334901, 0, 0, 116393707, 122619723, 0, 133629940, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_117[] = {
1703961, 2490406, 4849737, 0, 10223771, 0, 0, 13107399, 15007971, 15466732, 0, 0, 20513081, 23986542, 25624966, 0, 0, 30409168, 33030636, 0, 37093941, 0, 0, 0, 39518811, 0, 44499622, 52101910, 58262370, 62587834, 66913275, 0, 0, 0, 78906546, 79430844, 0, 89916763, 92538242, 99812848, 104465977, 109053568, 109774470, 116459249, 126224208, 0, 133826552, 0, 0, 138151995, 139200586, 0
};

static PRInt32 const HILO_ACCEL_118[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25887112, 0, 0, 0, 0, 0, 0, 38208071, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100206068, 104531515, 0, 0, 0, 0, 0, 0, 0, 0, 138217533, 0, 0
};

static PRInt32 const HILO_ACCEL_119[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44630696, 0, 58393466, 62653372, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100533754, 0, 0, 0, 0, 126551943, 130484165, 133892091, 0, 0, 138283070, 0, 140052568
};

static PRInt32 const HILO_ACCEL_120[] = {
0, 0, 0, 0, 10354845, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 67175422, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 116524786, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_121[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58459004, 0, 0, 0, 0, 75236475, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static PRInt32 const HILO_ACCEL_122[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62784445, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 126683020, 0, 0, 135989275, 0, 0, 0, 0
};

const PRInt32* const nsHtml5NamedCharacters::HILO_ACCEL[] = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  HILO_ACCEL_65,
  HILO_ACCEL_66,
  0,
  HILO_ACCEL_68,
  HILO_ACCEL_69,
  0,
  0,
  HILO_ACCEL_72,
  HILO_ACCEL_73,
  HILO_ACCEL_74,
  0,
  HILO_ACCEL_76,
  HILO_ACCEL_77,
  HILO_ACCEL_78,
  HILO_ACCEL_79,
  0,
  0,
  HILO_ACCEL_82,
  HILO_ACCEL_83,
  HILO_ACCEL_84,
  HILO_ACCEL_85,
  HILO_ACCEL_86,
  0,
  0,
  0,
  HILO_ACCEL_90,
  0,
  0,
  0,
  0,
  0,
  0,
  HILO_ACCEL_97,
  HILO_ACCEL_98,
  HILO_ACCEL_99,
  HILO_ACCEL_100,
  HILO_ACCEL_101,
  HILO_ACCEL_102,
  HILO_ACCEL_103,
  HILO_ACCEL_104,
  HILO_ACCEL_105,
  HILO_ACCEL_106,
  HILO_ACCEL_107,
  HILO_ACCEL_108,
  HILO_ACCEL_109,
  HILO_ACCEL_110,
  HILO_ACCEL_111,
  HILO_ACCEL_112,
  HILO_ACCEL_113,
  HILO_ACCEL_114,
  HILO_ACCEL_115,
  HILO_ACCEL_116,
  HILO_ACCEL_117,
  HILO_ACCEL_118,
  HILO_ACCEL_119,
  HILO_ACCEL_120,
  HILO_ACCEL_121,
  HILO_ACCEL_122
};

/**
 * To avoid having lots of pointers in the |charData| array, below,
 * which would cause us to have to do lots of relocations at library
 * load time, store all the string data for the names in one big array.
 * Then use tricks with enums to help us build an array that contains
 * the positions of each within the big arrays.
 */

static const PRInt8 ALL_NAMES[] = {
#define NAMED_CHARACTER_REFERENCE(N, CHARS, LEN, FLAG, VALUE) \
CHARS ,
#include "nsHtml5NamedCharactersInclude.h"
#undef NAMED_CHARACTER_REFERENCE
};

enum NamePositions {
  DUMMY_INITIAL_NAME_POSITION = 0,
/* enums don't take up space, so generate _START and _END */
#define NAMED_CHARACTER_REFERENCE(N, CHARS, LEN, FLAG, VALUE) \
NAME_##N##_DUMMY, /* automatically one higher than previous */ \
NAME_##N##_START = NAME_##N##_DUMMY - 1, \
NAME_##N##_END = NAME_##N##_START + LEN + FLAG,
#include "nsHtml5NamedCharactersInclude.h"
#undef NAMED_CHARACTER_REFERENCE
  DUMMY_FINAL_NAME_VALUE
};

#define NAMED_CHARACTERS_COUNT 2138

/* check that the start positions will fit in 16 bits */
PR_STATIC_ASSERT(NS_ARRAY_LENGTH(ALL_NAMES) < 0x10000);

struct NamedCharacterData {
  PRUint16 nameStart;
  PRUint16 nameLen;
#ifdef DEBUG
  PRInt32 n;
#endif
};

static const NamedCharacterData charData[NAMED_CHARACTERS_COUNT] = {
#ifdef DEBUG
  #define NAMED_CHARACTER_REFERENCE(N, CHARS, LEN, FLAG, VALUE) \
{ NAME_##N##_START, LEN, N },
#else
  #define NAMED_CHARACTER_REFERENCE(N, CHARS, LEN, FLAG, VALUE) \
{ NAME_##N##_START, LEN, },
#endif
#include "nsHtml5NamedCharactersInclude.h"
#undef NAMED_CHARACTER_REFERENCE
};

void
nsHtml5NamedCharacters::initializeStatics()
{
  NAMES = jArray<jArray<PRInt8,PRInt32>,PRInt32>(NAMED_CHARACTERS_COUNT);
  PRInt8* allNames = const_cast<PRInt8*>(ALL_NAMES);
  for (PRInt32 i = 0; i < NAMED_CHARACTERS_COUNT; ++i) {
    const NamedCharacterData &data = charData[i];
    NS_ABORT_IF_FALSE(data.n == i,
                      "index error in nsHtml5NamedCharactersInclude.h");
    NAMES[i] = jArray<PRInt8,PRInt32>(allNames + data.nameStart, data.nameLen);
  }

  WINDOWS_1252 = new PRUnichar*[32];
  for (PRInt32 i = 0; i < 32; ++i) {
    WINDOWS_1252[i] = (PRUnichar*)&(WINDOWS_1252_DATA[i]);
  }
}

void
nsHtml5NamedCharacters::releaseStatics()
{
  NAMES.release();
  delete[] WINDOWS_1252;
}
