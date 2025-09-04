

#define   SIN_ADD_FIRE			0x00000001	
#define   SIN_ADD_ICE			0x00000002	
#define   SIN_ADD_LIGHTNING			0x00000004	
#define   SIN_ADD_POISON			0x00000008	
#define   SIN_ADD_BIO			0x00000010	
#define   SIN_ADD_Critico			0x00000020	
#define   SIN_ADD_ATTACK_RATE		0x00000040	
#define   SIN_ADD_DAMAGE_MIN		0x00000080	
#define   SIN_ADD_DAMAGE_MAX		0x00000100	
#define   SIN_ADD_ATTACK_SPEED		0x00000200	
#define   SIN_ADD_ABSORB			0x00000400	
#define   SIN_ADD_DEFENCE			0x00000800	
#define   SIN_ADD_BLOCK_RATE		0x00001000	
#define   SIN_ADD_MOVE_SPEED		0x00002000	
#define   SIN_ADD_LIFE			0x00004000	
#define   SIN_ADD_MANA			0x00008000	
#define   SIN_ADD_STAMINA			0x00010000	
#define   SIN_ADD_LIFEREGEN			0x00020000 	
#define   SIN_ADD_MANAREGEN		0x00040000  	
#define   SIN_ADD_STAMINAREGEN		0x00080000  	

#define   SIN_ADD_NUM				1
#define   SIN_ADD_PERCENT			2





#define   SIN_ADD_FIRE			0x00000001	
#define   SIN_ADD_ICE			0x00000002	
#define   SIN_ADD_LIGHTNING			0x00000004	
#define   SIN_ADD_POISON			0x00000008	
#define   SIN_ADD_BIO			0x00000010	
#define   SIN_ADD_Critico			0x00000020	
#define   SIN_ADD_ATTACK_RATE		0x00000040	
#define   SIN_ADD_DAMAGE_MIN		0x00000080	
#define   SIN_ADD_DAMAGE_MAX		0x00000100	
#define   SIN_ADD_ATTACK_SPEED		0x00000200	
#define   SIN_ADD_ABSORB			0x00000400	
#define   SIN_ADD_DEFENCE			0x00000800	
#define   SIN_ADD_BLOCK_RATE		0x00001000	
#define   SIN_ADD_MOVE_SPEED		0x00002000	
#define   SIN_ADD_LIFE			0x00004000	
#define   SIN_ADD_MANA			0x00008000	
#define   SIN_ADD_STAMINA			0x00010000	
#define   SIN_ADD_LIFEREGEN			0x00020000 	
#define   SIN_ADD_MANAREGEN		0x00040000  	
#define   SIN_ADD_STAMINAREGEN		0x00080000  	

#define   SIN_ADD_NUM				1
#define   SIN_ADD_PERCENT			2





							
			{ { sinWA1, sinWC1, sinWH1, sinWM1, sinWP1, sinWS1, sinWS2, sinWT1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DAMAGE_MIN, SIN_ADD_DAMAGE_MAX, SIN_ADD_Critico, SIN_ADD_LIFE, 0, 0, 0, 0 },
			{ 6, 8, 2, 30, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+6 Poder de Ataque Min\r+8 Poder de Ataque Max\r+2 Crítico\r+30 HP\r" },

			{ { sinWD1, sinWN1, sinWV1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DAMAGE_MIN, SIN_ADD_DAMAGE_MAX, SIN_ADD_Critico, SIN_ADD_LIFE, 0, 0, 0, 0 },
			{ 6, 8, 2, 30, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+6 Poder de Ataque Min\r+8 Poder de Ataque Max\r+2 Crítico\r+30 HP\r" },

				
			{ { sinDA1, sinDA2, sinDA3, sinDA4, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ABSORB, SIN_ADD_MANA, 0, 0, 0, 0, 0 },
			{ 350, 6.0f, 110, 0, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0, 0 },
			"+350 Defesa\r+6.0 Absorção\r+110 MP\r" },

				
			{ { sinDS1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ABSORB, SIN_ADD_BLOCK_RATE, SIN_ADD_LIFE, SIN_ADD_MANA, 0, 0, 0 },
			{ 120, 1.0f, 3, 50, 10, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0 },
			"+120 Defesa\r+1.0 Absorção\r+3 Block\r+50 HP\r+10 MP\r" },

				
			{ { sinOM1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ABSORB, SIN_ADD_BLOCK_RATE, SIN_ADD_LIFE, 0, 0, 0, 0 },
			{ 170, 6.0f, 2, 45, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0 },
			"+170 Defesa\r+6.0 Absorção\r+2 Block\r+45 HP\r" },

				
			{ { sinOA2, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ATTACK_RATE, SIN_ADD_STAMINA, SIN_ADD_MANA, 0, 0, 0, 0 },
			{ 95, 110, 55, 40, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+95 Defesa\r+110 Taxa de ATQ.\r+55 RES\r+40 MP\r" },

				
			{ { sinDG1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ABSORB, SIN_ADD_MANA, SIN_ADD_STAMINA, 0, 0, 0, 0 },
			{ 150, 5.0f, 70, 120, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+150 Defesa\r+5.0 Absorção\r+70 MP\r+120 RES\r" },

				
			{ { sinDB1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_LIFE, SIN_ADD_MANA, SIN_ADD_MOVE_SPEED, 0, 0, 0, 0, 0 },
			{ 80, 50, 3.2f, 0, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0, 0 },
			"+80 HP\r+50 MP\r+3.2 Velocidade\r" },

				
			{ { sinOR1, sinOR2, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_LIFE, SIN_ADD_STAMINA, SIN_ADD_MANA, SIN_ADD_STAMINAREGEN, 0, 0, 0, 0 },
			{ 40, 40, 40, 3.8f, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+40 HP\r+40 RES\r+40 MP\r+3.8 RES Regen\r" },

				
			{ { sinOA1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_STAMINA, SIN_ADD_MANA, SIN_ADD_STAMINAREGEN, 0, 0, 0, 0, 0 },
			{ 40,40, 3.8f, 0, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0,0, 0 },
			"+40 RES\r+40 MP\r+3.8 RES Regen\r" },

				
			{ { sinOS1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DAMAGE_MIN, SIN_ADD_DAMAGE_MAX, 0, 0, 0, 0, 0, 0 },
			{ 1,1, 0, 0, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0,0, 0 },
			"+1 Poder de Ataque Min\r+1 Poder de Ataque Max\r" },

			

				

					
			{ { sinWA1, sinWC1, sinWH1, sinWM1, sinWP1, sinWS1, sinWS2, sinWT1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DAMAGE_MIN, SIN_ADD_DAMAGE_MAX, SIN_ADD_Critico, SIN_ADD_LIFE, 0, 0, 0, 0 },
			{ 8, 10, 2, 40, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+8 Poder de Ataque Min\r+10 Poder de Ataque Max\r+2 Crítico\r+40 HP\r" },

			{ { sinWD1, sinWN1, sinWV1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DAMAGE_MIN, SIN_ADD_DAMAGE_MAX, SIN_ADD_Critico, SIN_ADD_LIFE, 0, 0, 0, 0 },
			{ 8, 10, 2, 40, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+8 Poder de Ataque Min\r+10 Poder de Ataque Max\r+2 Crítico\r+40 HP\r" },

				
			{ { sinDA1, sinDA2, sinDA3, sinDA4, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ABSORB, SIN_ADD_MANA, 0, 0, 0, 0, 0 },
			{ 450, 8.0f, 150, 0, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0, 0 },
			"+450 Defesa\r+8.0 Absorção\r+150 MP\r" },

				
			{ { sinDS1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ABSORB, SIN_ADD_BLOCK_RATE, SIN_ADD_LIFE, 0, 0, 0, 0 },
			{ 180, 2.5f, 5, 100, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0 },
			"+180 Defesa\r+2.5 Absorção\r+5 Block\r+100 HP\r" },

				
			{ { sinOM1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ABSORB, SIN_ADD_BLOCK_RATE, SIN_ADD_MANA, 0, 0, 0, 0 },
			{ 270, 8.0f, 5, 200, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0 },
			"+270 Defesa\r+8.0 Absorção\r+5 Block\r+200 HP\r" },

				
			{ { sinOA2, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ATTACK_RATE, SIN_ADD_STAMINA, SIN_ADD_MANA, 0, 0, 0, 0 },
			{ 130, 150, 75, 55, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+130 Defesa\r+150 Taxa de ATQ.\r+75 RES\r+55 MP\r" },

				
			{ { sinDG1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ABSORB, SIN_ADD_MANA, SIN_ADD_STAMINA, 0, 0, 0, 0 },
			{ 200, 7.0f, 90, 160, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+200 Defesa\r+7.0 Absorção\r+90 MP\r+160 RES\r" },

				
			{ { sinDB1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_LIFE, SIN_ADD_MANA, SIN_ADD_MOVE_SPEED, 0, 0, 0, 0, 0 },
			{ 120, 70, 5.0f, 0, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0, 0 },
			"+120 HP\r+70 MP\r+5.0 Velocidade\r" },

				
			{ { sinOR1, sinOR2, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_LIFE, SIN_ADD_STAMINA, SIN_ADD_MANA, SIN_ADD_STAMINAREGEN, 0, 0, 0, 0 },
			{ 80, 80, 80, 4.3f, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+80 HP\r+80 RES\r+80 MP\r+4.3 RES Regen\r" },

				
			{ { sinOA1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_MANA, SIN_ADD_LIFEREGEN, SIN_ADD_MANAREGEN, 0, 0, 0, 0, 0 },
			{ 120,5.5f, 4.1f, 0, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0,0, 0 },
			"+120 MP\r+5.5 HP Regen\r+4.1 MP Regen\r" },

				
			{ { sinOS1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DAMAGE_MIN, SIN_ADD_DAMAGE_MAX, 0, 0, 0, 0, 0, 0 },
			{ 2,3, 0, 0, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0,0, 0 },
			"+2 Poder de Ataque Min\r+3 Poder de Ataque Max\r" },


				

					
			{ { sinWA1, sinWC1, sinWH1, sinWM1, sinWP1, sinWS1, sinWS2, sinWT1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DAMAGE_MIN, SIN_ADD_DAMAGE_MAX, SIN_ADD_Critico, SIN_ADD_LIFE, 0, 0, 0, 0 },
			{ 8, 10, 2, 40, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+8 Poder de Ataque Min\r+10 Poder de Ataque Max\r+2 Crítico\r+40 HP\r" },

			{ { sinWD1, sinWN1, sinWV1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DAMAGE_MIN, SIN_ADD_DAMAGE_MAX, SIN_ADD_Critico, SIN_ADD_LIFE, 0, 0, 0, 0 },
			{ 8, 10, 2, 40, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+8 Poder de Ataque Min\r+10 Poder de Ataque Max\r+2 Crítico\r+40 HP\r" },

				
			{ { sinDA1, sinDA2, sinDA3, sinDA4, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ABSORB, SIN_ADD_MANA, 0, 0, 0, 0, 0 },
			{ 450, 8.0f, 150, 0, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0, 0 },
			"+450 Defesa\r+8.0 Absorção\r+150 MP\r" },

				
			{ { sinDS1, 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ABSORB, SIN_ADD_BLOCK_RATE, SIN_ADD_LIFE, 0, 0, 0, 0 },
			{ 180, 2.5f, 5, 100, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0 },
			"+180 Defesa\r+2.5 Absorção\r+5 Block\r+100 HP\r" },

				
			{ { sinOM1, 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ABSORB, SIN_ADD_BLOCK_RATE, SIN_ADD_MANA, 0, 0, 0, 0 },
			{ 270, 8.0f, 5, 200, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0 },
			"+270 Defesa\r+8.0 Absorção\r+5 Block\r+200 HP\r" },

				
			{ { sinOA2, 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ATTACK_RATE, SIN_ADD_STAMINA, SIN_ADD_MANA, 0, 0, 0, 0 },
			{ 130, 150, 75, 55, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+130 Defesa\r+150 Taxa de ATQ.\r+75 RES\r+55 MP\r" },

				
			{ { sinDG1, 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DEFENCE, SIN_ADD_ABSORB, SIN_ADD_MANA, SIN_ADD_STAMINA, 0, 0, 0, 0 },
			{ 200, 7.0f, 90, 160, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+200 Defesa\r+7.0 Absorção\r+90 MP\r+160 RES\r" },

				
			{ { sinDB1, 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_LIFE, SIN_ADD_MANA, SIN_ADD_MOVE_SPEED, 0, 0, 0, 0, 0 },
			{ 120, 70, 5.0f, 0, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0, 0 },
			"+120 HP\r+70 MP\r+5.0 Velocidade\r" },

				
			{ { sinOR1, sinOR2, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_LIFE, SIN_ADD_STAMINA, SIN_ADD_MANA, SIN_ADD_STAMINAREGEN, 0, 0, 0, 0 },
			{ 80, 80, 80, 4.3f, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0 },
			"+80 HP\r+80 RES\r+80 MP\r+4.3 RES Regen\r" },

				
			{ { sinOA1, 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_MANA, SIN_ADD_LIFEREGEN, SIN_ADD_MANAREGEN, 0, 0, 0, 0, 0 },
			{ 120,5.5f, 4.1f, 0, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0,0, 0 },
			"+120 MP\r+5.5 HP Regen\r+4.1 MP Regen\r" },

				
			{ { sinOS1, 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ SIN_ADD_DAMAGE_MIN, SIN_ADD_DAMAGE_MAX, 0, 0, 0, 0, 0, 0 },
			{ 2,3, 0, 0, 0, 0, 0, 0 },
			{ SIN_ADD_NUM, SIN_ADD_NUM, 0, 0, 0, 0,0, 0 },
			"+2 Poder de Ataque Min\r+3 Poder de Ataque Max\r" },

				
			{ { sinOE1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 10, 0, 0, 0, 0, 0, 0, 0, 0 }, 
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0,0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0,0, 0 },
			"" },
