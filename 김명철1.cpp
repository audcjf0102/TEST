#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void title();
void start(int sel);
void line();
void dif(int sel);
void pro(int sel);
void s_way1(int sel);
void m1_food_way(int sel);
void m1_book_way1(int sel);
void af1_way(int sel);
void din1_bed(int sel);
int sleep_rand1();
void m2_story();
int af2_mouse(int sel);
void af2_radio();
void din2_food(int sel);
void m3_story();
int af3_store(int sel);
void af3_vil(int sel);
void di3();
void ra_end(int sel);
void eas(int sel);
void gujo(int sel);
void bad();


int heal, ment, mon, good = 0;
int ending = 0;
int inven[10] = { 0, };

void gotoxy(int x, int y) {
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
	int sel = 0;
	int random[3] = { 0,0,0 };
	srand(time(NULL));
	for (int i = 0; i <= 2; i++)
	{
		random[i] = rand() % 100 + 1;
	}
	//랜덤 값 저장
	title();//타이틀
	system("cls");

	start(sel);//시작메뉴
	line();

	dif(sel);//난이도
	line();

	pro(sel);//프롤로그
	line();

	s_way1(sel);//기본 선택지(총, 식료품, 강아지)
	line();

	if (random[0] <= 50) {
		m1_food_way(sel);
		line();
	}
	//음식
	if (ment == 0) {
		printf("멘탈이 0이 되어 게임오버되었습니다.\n"); exit(0);
	}

	else if (random[0] > 50) {
		m1_book_way1(sel);
		line();
	}
	//책

	af1_way(sel); //무장한 약탈자
	line();

	din1_bed(sel); //숙소
	if (heal < 0) {
		printf("체력이 0이 되어 게임오버되었습니다.\n"); exit(0);
	}
	else if (ment == 0) {
		printf("멘탈이 0이 되어 게임오버되었습니다.\n"); exit(0);
	}
	line();

	if (random[1] < 20) {
		sleep_rand1();
		line();
	}
	//수면 이벤트

	m2_story();//친구
	line();

	if (random[2] < 10) {
		af2_radio();
		line();
	}
	//라디오

	else if (random[2] >= 10) {
		af2_mouse(sel);
		if (heal < 0) {
			printf("체력이 0이 되어 게임오버되었습니다.\n"); exit(0);
		}
		line();
	}
	//괴물 쥐

	din2_food(sel);//식당
	line();

	m3_story();//친구2
	if (ment == 0) {
		printf("멘탈이 0이 되어 게임오버되었습니다.\n"); exit(0);
	}
	line();

	af3_store(sel);//트럭 상점
	line();

	af3_vil(sel);//마을
	line();

	di3();//마을
	line();
	


	if (good < 0) {
		bad();
		ending++;
	}
	//약탈자 엔딩

	if (ending == 0 && inven[0] != 0 && inven[3] != 0) {
		eas(sel);
		ending++;
	}
	//탈출 엔딩

	if (ending == 0 && inven[5] != 0) {
		ra_end(sel);
		ending++;
	}
	//라디오 엔딩

	if (ending == 0 && good >= 2) {
		gujo(sel);
		ending++;
	}//구조 엔딩
	//구조대 엔딩

}

void title()
{
	gotoxy(0, 4);
	printf("	■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                   서 울                                  ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                  2 0 3 3                                 ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                서 바 이 벌                               ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                                          ■\n");
	printf("	■                                                   아무키나 누르세요. . . ■\n");
	printf("	■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
	int a123;
	a123 = getch();
}
//게임 타이틀
void start(int sel)
{
	printf("1. 게임 시작\n2. 게임 설명\n3. 게임 종료\n선택 하세요 : ");
	scanf("%d", &sel);
	printf("\n");
	switch (sel) {
	case 1: printf("게임을 시작합니다.\n\n"); break;
	case 2: printf("이 게임은 서바이벌 형식입니다.\n각 선택지를 고르실 수 있으며 고르는 선택지에 따라 결과가 달라집니다.\n");
		printf("마지막까지 생존하시길 바랍니다.\n체력 혹은 멘탈이 0이 될경우 게임이 종료됩니다.\n*주의사항 : 선택지에 없는 번호를 선택할시에는 게임이 종료됩니다.\n\n"); break;
	case 3: printf("게임을 종료합니다.\n\n"); exit(0);
	default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0);
	}

}
//게임 시작 선택 메뉴
void line() {
	printf("=============================================================================\n");
	printf("=============================================================================\n\n");
	int a123;
	a123 = getch();
	if (a123 != (NULL))
		system("cls");
}
//경계선
void dif(int sel) {
	printf("난이도를 선택하세요\n\n1. easy\n2. nommal\n3. hard\n\n난이도를 선택하세요 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1: printf("easy 선택하셨습니다.\n\n체력, 멘탈, 현금이 4로 설정됩니다.\n\n"); mon = 4, heal = 4, ment = 4; break;
	case 2: printf("nommal 선택하셨습니다.\n\n체력, 멘탈, 현금이 3로 설정됩니다.\n\n"); mon = 3, heal = 3, ment = 3; break;
	case 3:	printf("hard 선택하셨습니다.\n\n체력, 멘탈, 현금이 2로 설정됩니다.\n\n"); mon = 2, heal = 2, ment = 2; break;
	default: printf("잘못된 입력입니다.\n게임을 종료합니다.\n\n"); exit(0);
	}
}
//난이도 선택
void pro(int sel) {
	printf("프롤로그를 진행합니다. 스킵하시겠습니까?\n\n1. 아니오\n2. 예\n선택하세요 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1: printf("진행합니다.\n\n\n");
		printf("2030년, 외교적 갈등이 극에 달한 국가들은 핵 전쟁을 시작합니다.\n");
		printf("핵을 보유한 국가들은 적대적 감정을 가진 국가들에 핵을 투하하고, 세계는 방사능과 전쟁에 뒤덮히고.\n");
		printf("개인의 방공호, 지하 대피소등의 공간에 있던 극소수만이 살아남았습니다.\n");
		printf("3년이 지난 2033년, 지하 대피소에서 연명하던 당신은 외부의 약탈자들로 인해 지내고있던 대피소가 침략당해 무너지고\n");
		printf("당신은 난잡한 틈을타 간신히 탈출에 성공합니다.\n");
		printf("차디찬 겨울 도시에 맨몸으로 던져진 당신은 앞으로 홀로 살아가야합니다.\n\n"); break;
	case 2: printf("스킵합니다.\n\n"); break;
	default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0);
	}
}
//프롤로그
void s_way1(int sel) {
	printf("당신은 대피소에서 탈출할 때 급박한 상황 속 한가지 물품을 챙길 수 있습니다. \n");
	printf("당신의 몸을 지키기 위한 총기, 생존에 필수품인 식료품,\n마지막으로는 구석에 떨고 있는 강아지 한마리입니다.\n");
	printf("무엇을 고르시겠습니까?\n\n");
	printf("1. 권총\n2. 식료품\n3. 강아지\n선택하세요 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1:printf("소지품에 권총이 추가됩니다.\n살상력이 뛰어나지만 다루기 힘들 것 같습니다.\n\n"); inven[0] = 1; break;
	case 2:printf("소지품에 식료품이 추가됩니다.\n\n"); inven[1] = inven[1] + 1; break;
	case 3:printf("여행에 강아지가 추가됩니다.\n든든한 동료역할을 하기도 하며 외로움을 달래줍니다.\n\n"); inven[2] = 1; good++; break;
	default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0);
	}
}
//기본 선택지(총, 식료품, 강아지)
void m1_food_way(int sel) {
	printf("이른 아침 당신은 암울한 기분으로 대피소를 떠나며 식료품을 구하기 위하여 어디로 갈지 선택해야 합니다.\n");
	printf("첫 번째는 식료품 마트, 두 번째는 지나가는 사람들을 약탈하는 것, 세 번째는 사냥을 통해 얻는 것입니다.\n");
	printf("하지만 마지막으로는 포기하는 것도 있습니다.\n");
	printf("1. 식료품마트\n2. 약탈\n3. 사냥\n4. 포기\n무엇을 선택하시겠습니까?\n선택하세요 : ");
	scanf("%d", &sel);
	int se;
	switch (sel) {
	case 1: {
		printf("당신은 식료품 마트로 떠납니다.\n식료품 마트의 문은 다 부서져있었고, 내부는 엉망진창이 되어있었습니다.\n");
		printf("당신은 아무것도 얻지못한채 식료품 마트를 나옵니다.\n\n"); break;
	}
	case 2: {
		printf("당신을 지나가는 사람들의 물건을 약탈하기로 결정합니다.\n");
		printf("저 멀리 지나가는 남자가 있습니다.\n");
	}
			if (inven[0] != 0) {
				printf("당신이 총으로 위협을 하자 걸어오던 남자는 당신에게 총을겨눕니다.\n하지만 쏘지는 않고 계속 위협만 합니다.\n");
				printf("총을 사용하시겠습니까?\n1. 예\n2. 아니오\n 선택하세요 : \n");
				scanf("%d", &se);
				switch (se) {
				case 1: {
					printf("당신이 총을 사용하자 남자는 떨리는 손으로 망설이는가 싶더니 이내 쓰러집니다.\n");
					printf("남성의 시체를 뒤지자 먹을만한 음식과 총을 얻습니다.\n식료품 + 1\n"); inven[1] = inven[1] + 1; inven[0] = 1;
					printf("그리고 가방속에 넣어둔 몇십장의, 각기 다른사람들이 쓴 편지들을 발견하고 놀랍니다.\n");
					printf("또한 남성의 총을 보자 아직..3발의 총알을 발견합니다.\n");
					printf("남성은 총알이 있음에도 당신을 쏘지 않았다는 것을 깨달았습니다.\n");
					printf("당신의 정신이 흔들립니다.\n멘탈 -1\n"); ment--; good--; break;
				}
				case 2: {
					printf("당신은 물건을 내놓으라고 위협하지만 남성은 총으로 당신을 위협합니다.\n");
					printf("당신은 어쩔 수 없이 물러납니다.\n"); good++; break;
				}
				default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0);
				}
			}
			else {
				printf("당신은 물건을 내놓으라고 위협하지만 남성은 총으로 당신을 위협합니다.\n");
				printf("당신은 어쩔 수 없이 물러납니다.\n"); break;
			}
	case 3: {
		printf("당신은 근처의 산으로 가 동물들을 찾아보지만...도시의 산에 동물이 있을리가 만무합니다.\n");
		printf("당신은 아무런 소득없이 산을 내려옵니다.\n"); break;
	}
	case 4: {
		printf("당신은 무엇도 선택하지 않고 그저 포기합니다.\n"); break;
	}
	default:
	{
		printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0);
	}
	}
}
//식료품 선택지(마트,약탈,사냥,포기)
void m1_book_way1(int sel) {
	printf("당신은 길을 떠나며 헌책들을 발견합니다.\n헌책들 사이에는 아직 읽을만한 책들이 있는것 같습니다.\n");
	printf("1. 서울 지도\n2. 혼자여도 외롭지않은 방법\n3. 사격의 정석\n선택하세요 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1: printf("서울 지도를 획득합니다.\n"); inven[3] = 1; break;
	case 2: printf("작가의 이야기가 공감이 됩니다..\n 멘탈 + 1\n"); ment = ment + 1; break;
	case 3: printf("총을 어떻게 써야할지 왠지 이해가 됩니다.\n"); inven[4] = 1; break;
	default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0); break;
	}
}
//책 선택지(지도, 멘탈, 사격술)
void af1_way(int sel) {
	printf("당신은 길을 걸어가는 중 한 무리와 마주합니다.\n");
	printf("그들은 군복을 입고 총으로 무장하고 있거나 흰색 가운을 입고 있습니다.\n");
	printf("당신은 그들을 보았지만 그들은 당신을 아직 발견하지 못했습니다. 어떻게 할까요?\n");
	printf("1. 공격\n2. 말을 걸어본다.\n3. 피해간다.\n선택하세요 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1: {
		printf("당신은 그들을 공격하지만 총으로 무장한 집단에게 이길리가 없습니다.\n");
		printf("당신의 몸은 벌집이 된 채로 죽어갑니다...\n\n");
		printf("게임이 종료됩니다.\n\n"); exit(0); break;
	}
	case 2: {
		printf("당신은 그들에게 말을걸기로 합니다.\n");
		printf("하지만 그들은 구조대가 아닌, 약탈자들이었습니다.\n");
		printf("당신은 가지고 있는 모든 금전들을 잃습니다...\n\n"); mon = 0; break;
	}
	case 3: {
		printf("구조대일지도 모르지만 아쉬움을 뒤로한채 확실한 안전을 선택합니다.\n"); break;
	}
	default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0);
	}
}
//무장한 약탈자
void din1_bed(int sel) {
	printf("당신은 대피소에서 탈출한 첫날을 무사히 지냈습니다.\n");
	printf("당신은 잘 곳을 찾아 이동하려고 합니다.\n");
	printf("하지만 폐허가 된 도시에서는 잘 곳을 찾기가 쉽지않습니다.\n");
	printf("긴 노력끝에 후보지 3곳을 찾았습니다.\n골목길에서 비박을 하는것, 형체만 남아있는 자동차트렁크, 공공화장실\n");
	printf("3가지 장소 모두 안락하지 않지만 하룻밤을 보낼수는 있을겁니다, 아마도 말이죠\n");
	printf("1. 골목길\n2. 자동차트렁크\n3. 공공화장실\n선택하세요 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1: printf("차가운 도시에서 골목길에서 비박을 하기에는 옳지 못한 생각인 것 같습니다.\n");
		printf("몸에 오한이 도는듯합니다.");
		printf("체력 - 1, 감기 + 1"); heal--; inven[6] = 1; break;
	case 2: printf("굉장히 좁아 몸이 찌뿌둥하고 여기저기가 쑤시지만, 하룻밤을 무사히 보냈습니다.\n"); break;
	case 3: printf("공공화장실로 들어서자 참을 수 없는 냄새가 납니다.\n");
		printf("심한 악취에 매우 고통스러워하며 잠에 듭니다.\n");
		printf("멘탈 - 1\n"); ment--; break;
	default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0);
	}
}
//숙소
int sleep_rand1()
{
	printf("당신이 잠에 든사이 어떤 사람이 당신의 짐을 뒤지기 시작합니다\n");
	if (inven[2] != 0) {
		printf("하지만 당신에겐 용감한강아지가 있어요! 강아지가 짖자 짐을 뒤지던 사람이 놀라 도망갑니다.\n");
		printf("그렇지만 당신은 그런사실을 모르고 계속 꺠지않습니다.\n"); return 0;
	}
	else {
		printf("그렇게 모든 식료품과 돈을 다 털리고 맙니다..\n"); mon = 0; inven[1] = 0;
	}
}
//수면 랜덤이벤트
void m2_story() {
	printf("그렇게 무사히 하루를 보낸 후 당신은 길을 나서다가 대피소에서 친하게 지내던 사람을 보고 기뻐합니다.\n");
	printf("못본 시간은 얼마되지않지만 서로 만난게 반가웠던 당신과 그는 한참을 얘기하며 지내다 이동하려합니다.\n");
	printf("그에게 같이 다닐것을 권유해보지만 그는 그저 웃으며 괜찮다고 합니다.\n");
	printf("당신은 무슨 이유가 있겠거니 하고 그를 보내며 내일 이 장소에서 다시 만나기로 합니다.\n");
	printf("그는 알겠다고 고개를 끄덕이며 당신에게 선물이라며 무언가를 주고 갑니다.\n");
	printf("그가 떠난 후 선물을 확인해보니 상당한 금액의 현찰이었습니다.\n");
	printf("돌려주려고 그를 불러보지만 그는 이미 보이지 않아 내일 전해주기로 합니다.\n\n");
	printf("현금 + 2, 멘탈 + 1\n"); mon = mon + 2; ment = ment + 1;
}
//친구
int af2_mouse(int sel) {
	printf("당신은 친구와 헤어지고 길을 걷던 중 꺼림칙한 소리와 마주합니다.\n");
	printf("소리가 나는곳으로 조심스레 이동하자 그곳에는 아주 거대한 생명체가 있었습니다.\n");
	printf("그런데...짜잔!! 그 생명체는 대략 2미터쯤 되어 보이는 커다란 앞발이 아주 커진 쥐였습니다.\n");
	printf("쥐는 초롱초롱한 눈으로 당신을 쳐다보고 있습니다\n어떻게 하시겠습니까?\n\n");
	printf("1. 무시하고 지나간다.\n2. 도망친다.\n3. 싸운다\n4. 먹을 것으로 유인한다.\n5. 총소리로 겁을 준다\n");
	while (1) {
		printf("선택하세요 : ");
		scanf("%d", &sel);
		switch (sel) {
		case 1: printf("애써 관심을 가지지않고 지나가자 쥐는 아무런 행동을 하지않습니다.\n"); return 0;
		case 2: printf("몸을 돌려 바로 도망치자 쥐는 관심도 가지지 않습니다.\n"); return 0;
		case 3: printf("당신은 용감히 쥐에게 달려들었지만 쥐에게 앞발로 맞고 날아갑니다\n체력 - 1\n\n"); heal--; return 0;
		case 4: {if (inven[1] != 0) {
			printf("당신은 긴장한채 가방에 있는 음식을 던져주자, 쥐는 음식에 정신이 팔립니다.\n");
			printf("하지만 소리는 끊기지 않았고, 주변을 둘러보자 그곳에는 라디오가있었습니다.\n\n");
			printf("라디오 획득\n"); inven[5] = 1; return 0;
		}
				else if (inven[1] == 0)
		{
			printf("음식이 다 떨어졌습니다..\n"); continue;
		}

		}
		case 5: {if (inven[0] != 0)
		{
			printf("총소리를 내자 깜짝 놀란 쥐는 잽싸게 도망갑니다\n"); return 0;
		}
				else if (inven[0] == 0)
		{
			printf("총이 없습니다.\n"); continue;
		}
		}
		default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0);
		}
	}
}
//괴물쥐
void af2_radio() {
	printf("당신은 친구와 헤어지고 길을 걷던 중 꺼림칙한 소리와 마주합니다.\n");
	printf("소리가 나는 곳으로 조심스레 이동하자 그곳에는 누군가가 떨어뜨린 듯한 라디오가 있었습니다.\n");
	printf("라디오 획득\n"); inven[5] = 1;
}
//라디오
void din2_food(int sel) {
	printf("당신은 잘 곳을 찾던 와중 운이 좋게 문이 열려있지만 멀쩡한 식당을 발견합니다.\n");
	printf("하지만 식료품은 누가 가져간 것인지 텅 비어있었습니다.\n");
	printf("우울한 기분으로 있던 당신은 식당에서 간신히 찾아낸 가스와 버너로 음식을 해먹으려합니다.\n");
	printf("그렇지만 당신은 무언가를 챙겨먹어야겠다고 다짐하고 식료품을 사용하려 합니다.\n사용하시겠습니까?\n");
	printf("1. 예\n2. 아니오\n선택하세요 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1: {
		if (inven[1] != 0) {
			printf("당신은 오랜만에 제대로 된 음식을 차려 먹고 행복하게 잠이 듭니다.\n멘탈 + 1"); ment++; break;
		}
		else if (inven[1] == 0) {
			printf("무언가를 해먹으려 했지만 텅 빈 가방을 보고 우울한 채로 잠이 듭니다.\n"); break;
		}
	}
	case 2:printf("무슨 일이 생길 줄 모르니 당신은 식료품을 아끼기로 하고 잠이 듭니다.\n"); break;
	default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0);
	}
}
//식당
void m3_story() {
	printf("길고 긴 밤이 지나고 아침이 밝았습니다.\n");
	printf("당신은 어제 친구와 한 약속을 지키기 위해 그 자리로 찾아갑니다.\n");
	printf("이게 어떻게 된 일일까요, 만나기로 한 장소에 친구가 나타나지 않습니다.\n");
	printf("당신은 친구를 찾아 나서기로 하고 어제 친구가 간 방향으로 걸어갑니다\n");
	printf("그렇게 걷던 중..친구의 것으로 보이는 가방을 발견합니다.\n");
	printf("가방이 놓여져있던 건물로 들어가자 목을 매달고 죽어있는 친구를 발견합니다.\n");
	printf("친구의 유서에는 이걸 읽은 당신혹은 누군가를 위한 글이 있었습니다.\n");
	printf("그것은 외부에 있는 도시, 서울을 벗어난 일부 도시에서는 아직 치안이 유지되어있다는 소식이었습니다.\n");
	printf("하지만 외곽에는 무장단체가 지키고 있으며, 쉽사리 나갈 수 없다고 경고합니다.\n");
	printf("친구의 죽음을 본 당신은 충격에 빠집니다\n멘탈 - 1\n"); ment--;
}
//친구2
int af3_store(int sel) {
	if (mon == 0) return 0;
	printf("친구의 죽음을 목격하고 정신이 나간 채로 터덜터덜 걷고 있을때 길가에 세워져 있는 트럭을 발견합니다\n");
	printf("트럭은 여러 가지를 팔고 있었고 그중에서는 쓸만해 보이는 것도 있었습니다.\n");
	printf("1. 의료품\n2. 식료품\n3. 아무것도 사지 않는다.\n4. 총기\n5. 책\n선택하세요 : ");
	scanf("%d", &sel);
	int se;
	switch (sel) {
	case 1:printf("의료품을 구입하셨습니다.\n"); inven[7] = inven[7] + 1; mon--; break;
	case 2:printf("식료품을 구입하셨습니다.\n"); inven[1] = inven[1] + 1; mon--; break;
	case 3:printf("아무것도 사지 않습니다.");
	case 4:printf("총기를 구입하셨습니다.\n"); inven[0] = inven[0] + 1; mon = mon - 2; break;
	default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0); break;
	case 5: {
		printf("1. 서울 지도\n2. 혼자여도 외롭지않은 방법\n3. 사격의 정석\n선택하세요 : ");
		scanf("%d", &se);
		switch (se) {
		case 1: printf("서울 지도를 획득합니다.\n"); inven[3] = 1; mon--; break;
		case 2: printf("작가의 이야기가 공감이 됩니다..\n 멘탈 + 1\n"); ment = ment + 1; mon--; break;
		case 3: printf("총을 어떻게 써야할지 왠지 이해가 됩니다.\n"); inven[4] = 1; mon--; break;
		default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0); break;
		}
	}
	}
}
//상점
void af3_vil(int sel) {
	printf("탐색도중 작은 마을을 발견합니다.\n");
	printf("마을에는 몇 안되는 아이들이 뛰어놀고 있었고 약 10명내외로 보이는 사람들이 있었습니다.\n");
	printf("마을에서 잠깐 쉬던 당신에게 아이가 달려와 자신의 친구가 아프다며 약을 나누어 줄 수 있냐고 묻습니다.\n");
	printf("1. 나누어 준다\n2. 나누어 주지 않는다.\n선택하세요 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1: { if (inven[7] != 0) {
		printf("당신은 약을 나누어 주기로 결정합니다. 아이가 고맙다며 연신 고개를 숙입니다.\n");
		inven[7] = inven[7] - 1; good++; break;
	}
			else printf("당신은 약을 주고 싶지만 없다고 합니다. 아이가 시무룩해하며 돌아갑니다."); break;
	}
	case 2: {
		if (inven[7] != 0) {
			printf("당신은 약을 가지고 있지만 나누어 주지 않습니다. 아이가 시무룩해하며 돌아갑니다.\n");
			printf("양심에 가책을 느낍니다.\n"); good--; break;
		}
		else printf("당신은 약을 가지고 있지 않다고 말합니다. 아이가 시무룩해하며 돌아갑니다.\n"); break;
	}
	default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0);
	}
}
//마을, 아이
void di3() {
	if (good >= 2) {
		printf("당신이 아이를 도와주었다는 것을 안 마을사람들은 얼마든지 머물러도 좋다고 합니다.\n");
		printf("당신은 마을에서 하룻밤을 지냅니다.\n");
	}
	else {
		printf("당신은 마을에서 나와 잘곳을 찾습니다. 하지만 잘곳이 마땅치 않아 비박을 하게됩니다.\n");
		printf("몸에 오한이 도는듯합니다.");
		printf("체력 - 1, 감기 + 1"); heal--; inven[6] = inven[6] + 1;
		if (inven[6] == 2) {
			printf("감기가 더욱 심해져 더 이상은 버티기 힘들 것 같습니다. 약을 먹어야 할 것 같습니다.\n");
			if (inven[7] != 0) {
				printf("약을 먹자 조금은 나아지는 듯 합니다.\n");
				inven[7] = inven[7] - 1; inven[6] = 1;
			}
			else {
				printf("하지만 당신은 약을 가지고 있지 않습니다..건강이 더욱 악화되는 것을 느낍니다.\n");
				printf("체력 - 1\n");
				heal--;
			}

		}
	}
}
//마을, 비박
void ra_end(int sel) {
	printf("무슨 일인지 자고 일어나니 마을은 텅 비어 있었습니다.\n");
	printf("자고 일어나 오랜만에 여유를 느끼고 있던 당신은 라디오에서 신호를 감지합니다.\n");
	printf("라디오의 내용은 외부에 있는 도시에서 온 구조대입니다!\n");
	printf("라는 내용으로 구조를 시행한다는 내용의 짧은 방송이었습니다.\n");
	printf("구조대에 도움을 받기 위해선 총기와 식료품을 반납해야 한다고 합니다.\n");
	printf("하지만 정말 이 사실을 믿을 수 있을까요? 결정은 당신의 몫입니다.\n");
	printf("1. 믿는다\n2. 믿지 않는다.\n선택하세요 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1: {
		printf("믿고 구조대의 말에 따른다.\n");
		printf("구조대는 군복과 하얀 가운을 입은 단체였으며 그들은 정말로 외부에서 온 구조대가 맞았습니다.\n");
		printf("당신은 구조대의 보호를 받으며 안전한 외부도시로 탈출하는데 성공합니다.\n");
		printf("ed_2 구조대"); break;
	}
	case 2: {
		printf("믿지 않는다.\n");
		printf("당신은 구조대라는 사실을 믿지 않았습니다.\n");
		printf("그 이후 라디오는 먹통이 난듯 아무런 소리도 나지않고 지직..거리는 소리만 반복하다 방전됩니다.\n");
		printf("방송이후 도시는 한산해졌으며 당신은 그저 하루하루 연명하며 살아갑니다.\n");
		printf("ed_5 방랑자"); break;
	}
	default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0);
	}
}
//라디오 엔딩
void gujo(int sel) {
	printf("마을에서 자고있던와중 마을 사람이 당신을 흔들어 깨웁니다.\n");
	printf("자신들은 구조대와 같이 이동할 것이라며 당신에게도 권유합니다.\n");
	printf("당신은 마을사람들을 믿고 구조대로 이동합니다.\n");
	printf("구조대에 도착하니 총기와 식료품을 반납 후 외부도시로 안전하게 이동됩니다.\n");
	printf("외부도시에 도착한 당신은 구조대로부터 구조대원의 권유를 받습니다.\n");
	printf("마을사람들이 당신을 추천했다며 구조대원으로 활동하는게 어떻냐고 묻습니다.\n");
	printf("1. 구조대원으로 활동한다\n 2. 활동하지 않는다.\n선택하세요 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1: {
		printf("당신은 구조대원으로써의 활동을 결정합니다.\n");
		printf("당신은 구조대원으로써 여러 도시의 마을로 파견을 나가 사람들을 돕습니다.\n");
		printf("그렇게 당신은 사람들의 선망을 받으며 살아갑니다.\n");
		printf("ed_6 구조대원"); break;
	}
	case 2: {
		printf("당신은 구조대원으로써의 활동을 거절합니다.\n");
		printf("당신은 구조대원으로써의 활동을 거절하고 그저 사람들 사이에서 살아갑니다.\n");
		printf("ed_2 구조대"); break;
	}
	}
}
//구조대 엔딩
void eas(int sel) {
	printf("당신은 외부도시로 가기 위해 길을 나섭니다.\n");
	printf("복잡한 서울의 지리와 여러 일들을 겪은 당신은 겨우겨우 외곽지역에 입성합니다.\n");
	printf("하지만 친구가 말했던 것처럼 외곽지역에는 무장단체가 지키고 있었습니다.\n");
	printf("몰래 지나가려 했지만 허술한 곳조차 경비가 1명씩은 있었습니다.\n");
	printf("경비들의 거리도 가까워 총성이 난후에는 별로 시간이 없을것 같습니다.\n");
	printf("경비들을 죽이고 지나가시겠습니까?\n1. 예\n2. 아니오\n선택하세요 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1: {
		if (inven[3] == 1)
		{
			printf("당신은 단 한번의 총격으로 경비를 제압하고 도시에서의 탈출에 성공합니다.\n");
			printf("당신은 외부도시로 가는 길을 찾았고, 외부도시에 도착하는데 성공합니다.\n");
			printf("ed_3 탈출\n"); break;
		}
		else {
			printf("당신은 총을 쐈지만 빗나가고 맙니다.\n");
			printf("총격에 놀란 경비는 경계태세를 취하고 엄폐합니다.\n");
			printf("그렇게 총격전을 벌이는 와중 하나 둘, 경비의 숫자가 늘어나며 당신은 사살되고 맙니다.\n");
			printf("ed_1 사망\n"); break;
		}
	case 2: {
		printf("당신은 탈출을 포기했고, 그저 도시에서 살아가기로 결심합니다.\n");
		printf("ed_5 방랑자\n"); break;
	}
	default: printf("잘못된 입력입니다. 게임을 종료합니다.\n\n"); exit(0);
	}
	}
}
//탈출 엔딩
void bad() {
	printf("당신은 생존을 위해서라면 비 윤리적인 행동을 일삼았습니다.\n");
	printf("점점 죄의식이 없어지며 약탈자들과 같아집니다..\n");
	printf("ed4_약탈자\n"); 
}
//약탈자 엔딩