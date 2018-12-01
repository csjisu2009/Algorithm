//time   : 0h 20m

/*review : 1. c buffer input
              it's redundant to input 2d char array in c
              references : http://cupjoo.tistory.com/74

           2. naive method - O(N^2)

           3. c function, strcmp
              references : https://code.woboq.org/userspace/glibc/string/strcmp.c.html

           4. the function I programmed have funcking bug!!
              bool bDictionaryOrderAB(char* a, char* b, int aSize, int bSize)
              I did not solved the problem yet..
              So I progammed strcmp() ( imitation of strCompare() ) instead of this bug function..

           5. 0, '\0', '0' - differences between them
              The first two of these are the same thing; they just represent an int with value 0.
              '0', however, is different, and represents an int with the value of the '0' character, which is 48.
*/
#include <stdio.h>
#include <string.h>//strcmp
#include <iostream>
using namespace std;

#define MAX 100

int n;
char str[MAX][MAX+1];

/*
//if a's dictionary order is faster than b, return true
//this function have fucking error!!
bool bDictionaryOrderAB(char* a, char* b, int aSize, int bSize){
    int shortSize;
    if(aSize <= bSize)
        shortSize = aSize;
    else
        shortSize = bSize;
    for(int i = 0 ; i < shortSize ; i++){
        printf("a[%d] : %c, b[%d] : %c\n", i, a[i], i, b[i]);
        if(a[i] < b[i])
            return true;
        if(b[i] < a[i])
            return false;
    }
    if(aSize <= bSize)//'a' is same as 'front of b'  but 'b' is longer than a - e) a = "abc", b = "abcddd"
        return true;
    else
        return false;
}
*/

//imitation of strcmp().. this code is very concise!!
int strCompare(char* a, char* b){
    int index = 0;
    char chA, chB;
    do{
        chA = a[index];
        chB = b[index];
        if(chA == '\0') return chA - chB;
        index++;
    }while(chA == chB);
    return chA - chB;
}

void changeOrder(int a, int b){
    char temp[MAX+1];
    int aLen = strlen(str[a]);
    int bLen = strlen(str[b]);
    for(int i = 0 ; i <= aLen ; i++)
        temp[i] = str[a][i];
    for(int i = 0 ; i <= bLen ; i++)
        str[a][i] = str[b][i];
    for(int i = 0 ; i <= aLen ; i++)
        str[b][i] = temp[i];
}

int main(){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
        cin >> str[i];
    int iLen, jLen;
    for(int i = 0 ; i < n-1 ; i++){
        iLen = strlen(str[i]);
        for(int j = i+1 ; j < n ; j++){
            jLen = strlen(str[j]);
            if(strCompare(&str[i][0], &str[j][0]) > 0)//if(!bDictionaryOrderAB(&str[i][0], &str[j][0], iLen, jLen)) - bug!!!!!!! fuck!!!!!!
                changeOrder(i, j);
        }
    }

    for(int i = 0 ; i < n ; i++)
        printf("%s\n", str[i]);

    return 0;
}

/*
test case

94
thvjzicnxijgrrmswj
pbvborozqzrdaitzve
xzzgrmzinfqtwuecovkcgxedfpoqqnsryyawiklfcvdnqwktmyzzouunfqkctzlcrlwmpuceqhqmrn
csgttoqupisqatyyddlykhfaoroymiyjmjmb
xrvifyyckxaapqjdszojgwfqdkvrwalbxfvyovjrqamf
ksjfouvesgqhmfutmtpoovmllqktbnjcfjogbbqupuphrobvkxwyivspkngmuryklwoocfclfvfhwwdbdgryod
rtwnknnh
ccjjgykvqxudkqxzqmosxdynfewszxgqdrmtg
nqqivrcnsqziqnihnlivrpovtoqjcpsnzbemnhhgcrirwgnhifvrwbvgghduxpitaywloqtfcpwegtczky
dirieodkxxjzxeckikxcmgdnhbbprktffoiblecvtpmwdqmxqeuxatijzhapgailhhovhbqnjioxtsachxklniiybkviyi
kefxgn
eycvrekmeqfuftjlazkdafknfxayovpqsgmowjbicbvsiholovrrhcfloamogb
eivrwhvjzlqwpphsfaqovqqrwlbsglkehrdefzsvfycuthcpwlykpenochpjyefmdblwnxtgeovsdxbqqqkbqbtzyhp
sboofiyi
z
rpuhmqloquuflabnejtrgsutoxxvnzckajukfnqgeglxxwnbxkumthqmoomyn
gkxffcmrbauwjjigtvrdkknpwfdsloamu
mynwhsepfkzxtlzvadeapnoxibzfmwkpfnuhlfkpmhlnoaupbibaybsnlvppnavbjchdlsftxcbcfptieqnbmyvwghdguku
jmzrglhsuigqcaarqkjwrizlazngxopovzxvcjhreiyjxmjczpsjvmzuidgmudvmgyntlymvfzeycmxy
wockawybjptudsitlazdsbjvjhictkoxtctklawptzvzrclvuqbvwqxnchqan
bnjwzqblloreflvbulebrtqmvpwguzrjoaedfgmdntvjgqlmkbhikhnbiqvgfhuumdcdnpyovspkmfew
bwerjtzwojqdyhrvumlrzrfevqnqroblsdlthpbibfypjwgtryaowhgqaszdheleifhmmyywbvucthnkhcydmdrvuotvgdw
fngzhfwvbfukwexqpjkkeehdbxzaxuzluccxsdymlfiwqmwbyxnztqjqktcjlaschuyfzcfzz
chpwtsitjuigcpubmxd
nfbiozaxiaomnaihappojsuxmnzzzasvasehqpjouefceululetfjesbsvsdpjeaecacbekknmrfjyaexrmqdnlsmwnlylgfd
nqejmhpkuxekx
jprugtrcpvzmaykcdegesdnjnkrcthukwovboaukbslyorzldneyvlptvviqhnzqpvjldpvukbuumfylmwlfeiljsbjdmd
gkrsizqfcxlrhvbeaqsgkpzirbtjoplkuncyifbyzyluikgytsgsvohwoezzkhfbl
tzcsvzltvqznoxderpjpnmgae
mizobgekmhdlaqcdnfmkexrwbxztiwyugqjpmc
jhvhgaoglgeoreklgjxozvdgpohkmzvetqqfovmjqjnkehjasiiggbyexjahokccuxntvqwtscapnfnxfgr
chbvmhtjxmoauqmpdrjdchhatoxijaejrbwylxptketxyujldvelwrmcwrgkmfkpwnaqexaakshlkyt
wjkrthbyjianroklfimtswffhkxegjdjwtuebxyptdxhlfkjrwqzlqoaodyexlfpfywabqsjxnlajpqawznavxlm
lsnbrhoanjjprlxrvmceycuuwatlnosarlysyodzyfkinfbnaoxqzbdpvycvda
deeuvtfjohzjngcusrrfivzpybgnyrbuqbglcnigeqjjhy
ypbcrhkyczrznoezlgphcgolqanswqesgmofdeuhwmjgjqvynxgwjwueokxzhcacdqe
nnrtguscoxzrjsnjekhgoghyvrrbpldipoqfgifsvuwuwepsyfmnleewtnddxcrrotcydmbygqvazkyjttbmjkcixzq
dhfcsfwrxatuc
iqbvoypmwhslozoqexxohsqiseeturukrynrqaqpeofjupcyiikqvueqihfyunqq
aoxbkblenyirbifikuvtjekuqheafmcvwvuegddmvwezpwsjzzcrfdwyfaikh
xpopwszdixoucpflqnkumenclfesoiluyy
ykawgcknyzmgnurmakxoxadqoc
nbvepkfcwlivdvfdighmqiheynmuichijqtfkpvzwhpbvnyoiymeniiocfdfghfkg
yd
qeflyjskhvoaxyqncncosisnhnyuhmvkwuaoajsjqcvwggixacjsdxwb
syannnpasihhwrnduzllidnlwseofttcqeyegraxmmxdvlhbzepeoiunhsw
pydubmyjoajfmhukyrqxrpncxfjnvmhiddagzpdmurlsoskbqdmkrvneprfpskgpptatbtrhhqz
rxcnxxvewsqemvvsznhrsqawqfqpszvsyghykvrvtqwlzgfeytzoptqndxfmjrocgmtcjjhraosjcrcbdtv
yyuwkvdgdkovhlmuolaldpyejvovwwpzatxfyxskkctgmpxdhhzhvyjxmbpttmshgcdllglurogy
udqsfuhgrhokqzpoqlltvqk
qjzvjbprxnhnmukqtaazmwpgdoomw
ngyreyfmtmynivrdzylnvzwqgeqpurzhyaxhuesbsykpkotqbuybnwkj
smfvghcrocsqpeykbgxfkfxmfxiyoc
dkqicspaoccghypkyzascgtqyuggzzrkfaumpvqec
jxtqihsyquxxlgmubgscfxezpnauswnxyztjxvfqihy
jsppqlnsofcgbxzmwtyvcwaaviuswqxszhvfxrurbgzluiowcgdwpsmucolykchabrgypuydetarcajcxspmyjzdcrj
brdklmvmielmcopvlhcjsmwrwdvluohcgyxnoxqlcxsqhzryjcambwilwfjqnsqvskpggwaotxbuv
dgaccyqjxwkpqgvwebuisqbwwaahdpmjgqdrpnkelhffcsqobdbkbokvibscledua
s
fgtnncuk
padixewcxhylbbnslwffpslnzkhxmtaultcmiyoiqwmsiwmogrbhnvkqiikufibzjgsxjlicvi
tboofjaljndfoxblarzirwmdhbkrhvgdikepsdbjhaywvjucryvddobjpzhaidam
trchhnvpnas
nwyhcwjdjpqvynkkjeblbyhxmyozasykqmpms
uzzbnerahbzpkmufowxcovhjbjdknihtguoklcnaslewfftlbvslqkpbhorapxrfwdjocphjoxetukmgnqbevsgvh
eokuwdtqyreiudnvjsqpikndcjt
ufuiakyrhuyuwwbmufdplpvjne
rcqhnkqaoluqcrwmxqyrmpgbmpi
kkfhsbweqkblusqprqueuogqtznkkptodavcfebdxcbjrsnhpbbuxwddjipcikmbirmzueknvjmtxdi
jjatgixpawxeuhgqdgooislbhtpphsliuuifsvdvwoadshxxcjlejsoqcdmrjmtvhzfllohdaquxkbvngmzgag
etjlymstazxhffmywjwvtoswjzfshcetjkjpgbbxnkyvwdsyqlsreprncvouavrmnwdoqvcshsfcvlxqik
jwjeyputuhctixywdfpacmqnsdopztlumisiiwxxbfztrgzpnqeueddvdmdulblhnaxwwetefisv
tgupbzwfkoaxydjxbnpoukpdopvmwjhmcipvkucusdycxrnjwmsxdobblfnlyebhbeioh
pgohessjdjythbbhdpruymgitishiohtvlngdf
rrqfzeylnidtxrxxbnfmvlxpliqujxtetacmpmfdhrbxnxeevugwkocaohxhzsskqlnfbshxejjrfjjeunvat
ovvpkwpryogpeivldhuvuhukhqfqemqtmjo
lyiyfpsdflnlyrqqccsgbfsynwftptklyznimfmfxvizpcofnjagchxkzqhiwiimzezm
jxkfbdlscgap
vflalavmevcfeomyocagqjhrzqc
vfroihbuekznejwwrgbfcrjjslqbfwdcfhqvsurrpfmijnjfogdz
pnoowwmdyeaytybfgexjayfjorkadw
gkatawzdivejqmx
rwwfslqxkjbfgpcpcksccyetnyeqjlyygkuqwynzyphcupaxiukzzrz
hjmzufwvmpnjlfyfbimnbktfrvdjsyqeccwgqdefuqoq
ordpyadgmmpjdftfsewmukdylbotutxwxrjwlpwyuaorkwmp
whzekcmvwzyotkyvorfuyxvobnqzssnrfkpycbefnjozzaiqpjntstuaqrpfclwihtqvcmyoghdeodwjyaxuncbhlcxci
hlxoekzgizzwjugvbgkstwmxuaxturcxppffbzsukzyh
aeadbhrpzpzqzbbwjjautpildmcabymelnkbxinpajlcrxxwidmqmusn
oteproivnjuaormoklouhzzwppeorocvulmogbvxezmkkwwb
awovvriajuicmdtfgscpuhtrtepqbfnxmswsnlroqbpuwc
adapyoatqtfefdahcqiirmcjxzyvxhkexkapklcxrpzqjttxcncjijdnavkxitmnpnwyy
gasskbwhjxqtsydmzkwdpiocnhcntbtdlglpn
hfmeavasgkrfiruxuzjicxgicsbmcjatjcmzldqivykaimnjentmxmzbibmrkgnxmiietfr
uqoqfxggoibrvwfovj
*/

/*
test case 2

30
thvjzicnxijgrrmswj
pbvborozqzrdaitzve
xzzgrmzinfqtwuecovkcgxedfpoqqnsryyawiklfcvdnqwktmyzzouunfqkctzlcrlwmpuceqhqmrn
csgttoqupisqatyyddlykhfaoroymiyjmjmb
xrvifyyckxaapqjdszojgwfqdkvrwalbxfvyovjrqamf
ksjfouvesgqhmfutmtpoovmllqktbnjcfjogbbqupuphrobvkxwyivspkngmuryklwoocfclfvfhwwdbdgryod
rtwnknnh
ccjjgykvqxudkqxzqmosxdynfewszxgqdrmtg
nqqivrcnsqziqnihnlivrpovtoqjcpsnzbemnhhgcrirwgnhifvrwbvgghduxpitaywloqtfcpwegtczky
dirieodkxxjzxeckikxcmgdnhbbprktffoiblecvtpmwdqmxqeuxatijzhapgailhhovhbqnjioxtsachxklniiybkviyi
kefxgn
eycvrekmeqfuftjlazkdafknfxayovpqsgmowjbicbvsiholovrrhcfloamogb
eivrwhvjzlqwpphsfaqovqqrwlbsglkehrdefzsvfycuthcpwlykpenochpjyefmdblwnxtgeovsdxbqqqkbqbtzyhp
sboofiyi
z
rpuhmqloquuflabnejtrgsutoxxvnzckajukfnqgeglxxwnbxkumthqmoomyn
gkxffcmrbauwjjigtvrdkknpwfdsloamu
mynwhsepfkzxtlzvadeapnoxibzfmwkpfnuhlfkpmhlnoaupbibaybsnlvppnavbjchdlsftxcbcfptieqnbmyvwghdguku
jmzrglhsuigqcaarqkjwrizlazngxopovzxvcjhreiyjxmjczpsjvmzuidgmudvmgyntlymvfzeycmxy
wockawybjptudsitlazdsbjvjhictkoxtctklawptzvzrclvuqbvwqxnchqan
bnjwzqblloreflvbulebrtqmvpwguzrjoaedfgmdntvjgqlmkbhikhnbiqvgfhuumdcdnpyovspkmfew
bwerjtzwojqdyhrvumlrzrfevqnqroblsdlthpbibfypjwgtryaowhgqaszdheleifhmmyywbvucthnkhcydmdrvuotvgdw
fngzhfwvbfukwexqpjkkeehdbxzaxuzluccxsdymlfiwqmwbyxnztqjqktcjlaschuyfzcfzz
chpwtsitjuigcpubmxd
nfbiozaxiaomnaihappojsuxmnzzzasvasehqpjouefceululetfjesbsvsdpjeaecacbekknmrfjyaexrmqdnlsmwnlylgfd
nqejmhpkuxekx
jprugtrcpvzmaykcdegesdnjnkrcthukwovboaukbslyorzldneyvlptvviqhnzqpvjldpvukbuumfylmwlfeiljsbjdmd
gkrsizqfcxlrhvbeaqsgkpzirbtjoplkuncyifbyzyluikgytsgsvohwoezzkhfbl
tzcsvzltvqznoxderpjpnmgae
mizobgekmhdlaqcdnfmkexrwbxztiwyugqjpmc
*/





/*

//c version
#include <stdio.h>
#include <string.h>

#define MAX 100

int n;

bool bDictionaryOrderAB(char* a, char* b, int aSize, int bSize){
    for(int i = 0 ; i < aSize ; i++){
        if(a[i] > b[i])
            return false;
    }
    if(aSize <= bSize)
        return true;
    else
        return false;
}

void changeOrder(char** str, int a, int b){
    char temp[MAX+1];
    int aLen = strlen(str[a]);
    int bLen = strlen(str[b]);
    for(int i = 0 ; i <= aLen ; i++)
        temp[i] = str[a][i];
    for(int i = 0 ; i <= bLen ; i++)
        str[a][i] = str[b][i];
    for(int i = 0 ; i <= aLen ; i++)
        str[b][i] = temp[i];
}

int main(){
    char str[MAX][MAX+1];
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
        cin >> str[i];
    //test
    //for(int i = 0 ; i < n ; i++)
    //    printf("%s\n", str[i]);
    int iLen, jLen;
    for(int i = 0 ; i < n-1 ; i++){
        iLen = strlen(str[i]);
        for(int j = i+1 ; j < n ; j++){
            jLen = strlen(str[j]);
            if(bDictionaryOrderAB(&str[i][0], &str[j][0], iLen, jLen))
                changeOrder(&str, i, j);
        }
    }

    //test
    for(int i = 0 ; i < n ; i++)
        printf("%s\n", str[i]);

    return 0;
}
*/