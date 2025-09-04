






#include "..\\sinLinkHeader.h"





DWORD sinNotToggleSkill_CODE[][5] =
{

	{SKILL_RAGE_UP},
	{SKILL_I_BULKUP},
	{SKILL_STEELERS},

	{SKILL_C_HUNT},
	{SKILL_A_MIGAL},
	{SKILL_A_MIDRANDA},
	{SKILL_R_MAKER},
	{SKILL_R_KNIGHT},
	{SKILL_RAGE_UP},
	{SKILL_I_BULKUP},
	{SKILL_STEELERS},
	{SKILL_ALAS},
	{SKILL_BLIND},
	{SKILL_INPES},

    {SKILL_MAXIMIZE,SKILL_METAL_ARMOR},
	{SKILL_HOLY_BODY,SKILL_DRASTIC_SPIRIT,0},
	{SKILL_ZENITH,0},
	{SKILL_WINDY,0},
	{SKILL_HOLY_REFLECTION,0},
	{SKILL_SPIRIT_ELEMENTAL,0},
	{SKILL_DANCING_SWORD,0},
	{SKILL_CONCENTRATION,0},
	{SKILL_SWIFT_AXE,0},
	{SKILL_FALCON,0},
	{SKILL_GOLDEN_FALCON,0},
	{SKILL_SCOUT_HAWK,0},
	{SKILL_DIVINE_INHALATION,0},
	{SKILL_METAL_ARMOR,0},
	{SKILL_SPARK_SHIELD,0},
	{SKILL_VANISH,0},
	{SKILL_GODLY_SHIELD,0},
	{SKILL_GOD_BLESS,0},
	{SKILL_FROST_JAVELIN,0},
	{SKILL_REGENERATION_FIELD,0},
	{SKILL_SUMMON_MUSPELL,0},
	{SKILL_FIRE_ELEMENTAL,0},
	{SKILL_DISTORTION,0},

	{SKILL_MAGNETIC_SPHERE,0},
	{SKILL_METAL_GOLEM,0},
	{SKILL_BERSERKER,0},
	{SKILL_B_BERSERKER,0},
	{SKILL_AMPLIFIED,0},
	{SKILL_TALARIA,0},
	{SKILL_ANIMA,0},
	{SKILL_TENUS,0 },
	{SKILL_RAMIEL, 0},
	{SKILL_KRISHNA, 0},
	{SKILL_H_SONIC, 0},
	{SKILL_P_ENHENCE, 0},
	{SKILL_ASSASSIN_EYE,0},
	{SKILL_VAGUE,0},
	{SKILL_RECALL_WOLVERIN,0},
    {SKILL_ARCUDA, 0},

	{SCROLL_INVULNERABILITY,0},
	{SCROLL_CRITICAL,0},
	{SCROLL_EVASION,0},
	{STONE_R_FIRECRYTAL,0},
	{STONE_R_ICECRYTAL,0},
	{STONE_R_LINGHTINGCRYTAL,0},
	{STONE_A_FIGHTER,0},
	{STONE_A_MECHANICIAN,0},
	{STONE_A_PIKEMAN,0},
	{STONE_A_ARCHER,0},
	{STONE_A_KNIGHT,0},
	{STONE_A_ATALANTA,0},
	{STONE_A_MAGICIAN,0},
	{STONE_A_PRIESTESS,0},

	0,
};
// Função: sinCheckSkillUseOk
// Verifica se o uso de uma habilidade é permitido.
// Parâmetros: lpSkill - Ponteiro para a estrutura da habilidade (sSKILL).
int sinCheckSkillUseOk(sSKILL* lpSkill)
{

	// Inicializa a flag de cancelamento de habilidade contínua.
	ContinueSkillCancelFlag = 0;
	// Declara variáveis de loop.
	int i = 0;
	int j = 0;

	// Verifica as informações de habilidade do personagem. Se falhar, retorna FALSE.
	if (!cSkill.CheckCharSkillInfo())return FALSE;

	// Define uma máscara para extrair o código da classe do personagem da habilidade.
#define  CHAR_SKILL_MASK 0xFF000000

	// Arrays que mapeiam códigos de personagem a códigos de grupo de habilidades.
	int   CharCode[11] = { SIN_CHAR_MECANICIAN,SIN_CHAR_FIGHTER,SIN_CHAR_ARCHER,SIN_CHAR_PIKEMAN,SIN_CHAR_KNIGHT,SIN_CHAR_ATALANTA,SIN_CHAR_PRIESTESS,SIN_CHAR_MAGICIAN,SIN_CHAR_ASSASSINE,SIN_CHAR_SHAMAN,SIN_CHAR_MARTIAL };
	DWORD CharSkillCode[11] = { GROUP_MECHANICIAN,GROUP_FIGHTER ,  GROUP_ARCHER,GROUP_PIKEMAN,GROUP_KNIGHT,GROUP_ATALANTA,GROUP_PRIESTESS,GROUP_MAGICIAN,GROUP_ASSASSINE,GROUP_SHAMAN,GROUP_MARTIAL };

	// Loop para verificar se a habilidade pertence à classe do personagem atual.
	for (int j = 0; j < 11; j++)
	{
		// Se o código do personagem atual corresponde a um código na lista...
		if (CharCode[j] == sinChar->JOB_CODE)
		{
			// ...e se o código da habilidade (mascarado) não corresponde ao código de grupo da classe...
			if ((lpSkill->CODE & CHAR_SKILL_MASK) != CharSkillCode[j])
			{
				// ...então a habilidade não pode ser usada por esta classe, retorna FALSE.
				return FALSE;
			}
		}
	}




	// Bloco de verificação de custo de mana com base em itens premium e buffs.
	// Se o tempo de poção de redução de mana, o tempo de Terry e o scroll de gravidade estiverem ativos...
	if (chaPremiumitem.m_ManaReducePotiontime > 0 && chaPremiumitem.m_TerryTime > 0 && sinChar->GravityScroolCheck[1] == 1)
	{
		// ...verifica se a mana atual é suficiente após as reduções. Se não, retorna FALSE.
		if (sinGetMana() - (lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] - ((lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] * chaPremiumitem.m_ManaReducePotionValue / 100) +
			(lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] * 20 / 100))) < 0)
			return FALSE;
	}


	// Caso contrário, se apenas o tempo de poção de redução de mana estiver ativo...
	else if (chaPremiumitem.m_ManaReducePotiontime > 0)
	{
		// ...verifica se a mana atual é suficiente após a redução. Se não, retorna FALSE.
		if (sinGetMana() - (lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] - (lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] * chaPremiumitem.m_ManaReducePotionValue / 100)) < 0)
			return FALSE;
	}

	// Caso contrário, se o tempo de Terry e o scroll de gravidade estiverem ativos...
	else if (chaPremiumitem.m_TerryTime > 0 && sinChar->GravityScroolCheck[1] == 1)
	{
		// ...verifica se a mana atual é suficiente após a redução. Se não, retorna FALSE.
		if (sinGetMana() - (lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] - (lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] * 20 / 100)) < 0)
			return FALSE;
	}

	// Caso contrário (nenhum dos buffs de redução de mana está ativo)...
	else
	{
		// ...verifica se a mana atual é suficiente para o custo total da habilidade. Se não, retorna FALSE.
		if ((sinGetMana() - lpSkill->Skill_Info.UseMana[lpSkill->Point - 1]) < 0)
			return FALSE;
	}





	// Declara variáveis para contagem de habilidades e loops.
	int CntSkillNum = 0;
	int k = 0;

	// Declara e inicializa Index3 para buscar habilidades contínuas.
	int Index3 = 0;
	// Verifica se a habilidade SKILL_FORCE_OF_NATURE está ativa como habilidade contínua.
	if (Index3 = cSkill.SearchContiueSkillIndex(SKILL_FORCE_OF_NATURE)) {
		// Se estiver ativa e a habilidade atual for SKILL_FORCE_OF_NATURE, retorna FALSE (não pode usar novamente).
		if (ContinueSkill[Index3 - 1].Flag == 1 && lpSkill->CODE == SKILL_FORCE_OF_NATURE)
			return FALSE;
	}

	// Verifica se a habilidade SKILL_HALL_OF_VALHALLA está ativa como habilidade contínua.
	if (Index3 = cSkill.SearchContiueSkillIndex(SKILL_HALL_OF_VALHALLA)) {
		// Se estiver ativa e a habilidade atual for SKILL_HALL_OF_VALHALLA, retorna FALSE (não pode usar novamente).
		if (ContinueSkill[Index3 - 1].Flag == 1 && lpSkill->CODE == SKILL_HALL_OF_VALHALLA)
			return FALSE;
	}

	// Loop infinito para verificar habilidades que não podem ser usadas juntas (toggle skills).
	while (1)
	{
		// Se não houver mais habilidades na lista sinNotToggleSkill_CODE, sai do loop.
		if (!sinNotToggleSkill_CODE[CntSkillNum][0])break;
		// Loop interno para verificar cada habilidade no grupo atual.
		for (i = 0; 0 != sinNotToggleSkill_CODE[CntSkillNum][i]; i++)
		{
			// Se a habilidade atual lpSkill->CODE estiver no grupo de habilidades que não podem ser usadas juntas...
			if (sinNotToggleSkill_CODE[CntSkillNum][i] == lpSkill->CODE)
			{

				// ...então, verifica todas as habilidades no mesmo grupo.
				for (k = 0; 0 != sinNotToggleSkill_CODE[CntSkillNum][k]; k++)
				{
					// Loop para verificar todas as habilidades contínuas ativas.
					for (j = 0; j < MAX_CONTINUE_SKILL; j++)
					{
						// Se uma habilidade contínua estiver ativa e for uma das habilidades no grupo que não podem ser usadas juntas...
						// ...então a habilidade atual não pode ser usada, retorna FALSE.
						if (ContinueSkill[j].Flag && ContinueSkill[j].CODE == sinNotToggleSkill_CODE[CntSkillNum][k])
						{
							return FALSE;
						}
					}
				}
			}
		}
		// Incrementa o contador de grupos de habilidades.
		CntSkillNum++;
	}


	// Declara flags para verificação de uso de arma.
	int UseFlag = 0;
	int UseFlag2 = 0;

	// Se a habilidade requer uma arma específica (UseWeaponCode[0] é diferente de zero)...
	if (lpSkill->Skill_Info.UseWeaponCode[0]) {
		UseFlag = 1; // Define UseFlag para indicar que uma arma é necessária.
		// Loop para verificar se o personagem tem a arma necessária equipada.
		for (int i = 0; i < 8; i++) {
			// Se houver um código de arma especificado para esta posição...
			if (lpSkill->Skill_Info.UseWeaponCode[i]) {
				// ...e se a arma equipada no slot principal (sInven[0].ItemIndex - 1) corresponde ao código da arma necessária...
				if (lpSkill->Skill_Info.UseWeaponCode[i] == (cInvenTory.InvenItem[sInven[0].ItemIndex - 1].CODE & sinITEM_MASK2)) {
					UseFlag2 = 1; // Define UseFlag2 para indicar que a arma correta está equipada.
					break; // Sai do loop, pois a arma foi encontrada.
				}
			}
		}
	}


	// Verificação específica para a habilidade SKILL_METAL_ARMOR.
	if (lpSkill->CODE == SKILL_METAL_ARMOR) {
		// Se houver um item equipado no slot de armadura (sInven[2].ItemIndex)...
		if (sInven[2].ItemIndex) {
			// ...e se o item equipado corresponde à classe do personagem (JobBitMask)...
			if (cInvenTory.InvenItem[sInven[2].ItemIndex - 1].sItemInfo.JobCodeMask == sinChar->JobBitMask) {
				// ...e se a flag de uso da habilidade estiver ativa...
				if (lpSkill->UseSkillFlag) {
					return TRUE; // Retorna TRUE, a habilidade pode ser usada.
				}
			}
		}
		return FALSE; // Se não atender às condições, retorna FALSE.
	}

	// Se a habilidade requer uma arma (UseFlag é 1)...
	if (UseFlag) {
		// ...e a arma correta estiver equipada (UseFlag2 é 1) e a flag de uso da habilidade estiver ativa...
		if (UseFlag2 && lpSkill->UseSkillFlag)
			return TRUE; // Retorna TRUE, a habilidade pode ser usada.
	}
	// Caso contrário (a habilidade não requer uma arma ou a arma não foi encontrada)...
	else {
		// ...se a flag de uso da habilidade estiver ativa...
		if (lpSkill->UseSkillFlag)
			return TRUE; // Retorna TRUE, a habilidade pode ser usada.
	}


	// Verificação para habilidades que requerem um escudo específico.
	// Se a habilidade for uma das habilidades de escudo listadas...
	if (lpSkill->CODE == SKILL_SHIELD_STRIKE || lpSkill->CODE == SKILL_EXTREME_SHIELD || lpSkill->CODE == SKILL_DIVINE_INHALATION || lpSkill->CODE == SKILL_SPARK_SHIELD || lpSkill->CODE == SKILL_GODLY_SHIELD) {
		// ...e se a flag de uso da habilidade estiver ativa...
		if (lpSkill->UseSkillFlag) {
			// ...e se o código da arma necessária para a habilidade corresponde ao item equipado no slot de escudo (sInven[1].ItemIndex - 1)...
			if (lpSkill->Skill_Info.UseWeaponCode[0] == (cInvenTory.InvenItem[sInven[1].ItemIndex - 1].CODE & sinITEM_MASK2)) {
				return TRUE; // Retorna TRUE, a habilidade pode ser usada.
			}
		}
	}


	// Verificação específica para a habilidade SKILL_SOUL_SUCKER.
	if (lpSkill->CODE == SKILL_SOUL_SUCKER) {
		// Se o item equipado no slot de escudo (sInven[1].ItemIndex - 1) for do tipo ITEM_KIND_CRAFT ou ITEM_KIND_AGING...
		if (cInvenTory.InvenItem[sInven[1].ItemIndex - 1].sItemInfo.ItemKindCode == ITEM_KIND_CRAFT ||
			cInvenTory.InvenItem[sInven[1].ItemIndex - 1].sItemInfo.ItemKindCode == ITEM_KIND_AGING) {
			// ...e se o código da arma necessária para a habilidade corresponde ao item equipado no slot de escudo...
			if (lpSkill->Skill_Info.UseWeaponCode[0] == (cInvenTory.InvenItem[sInven[1].ItemIndex - 1].CODE & sinITEM_MASK2)) {
				// ...e se a flag de uso da habilidade estiver ativa...
				if (lpSkill->UseSkillFlag) {
					return TRUE; // Retorna TRUE, a habilidade pode ser usada.
				}
			}
		}

	}
	return FALSE; // Se nenhuma das condições acima for atendida, retorna FALSE.
}

// Função: sinUseManaStamina
// Deduz a mana e/ou stamina do personagem ao usar uma habilidade.
// Parâmetros: lpSkill - Ponteiro para a estrutura da habilidade (sSKILL).
int sinUseManaStamina(sSKILL* lpSkill)
{











	// Bloco de dedução de mana com base em itens premium e buffs.
	// Se o tempo de poção de redução de mana, o tempo de Terry e o scroll de gravidade estiverem ativos...
	if (chaPremiumitem.m_ManaReducePotiontime > 0 && chaPremiumitem.m_TerryTime > 0 && sinChar->GravityScroolCheck[1] == 1)
	{
		// ...deduz a mana com as reduções aplicadas.
		sinSetMana(sinGetMana() - (lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] -
			((lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] * chaPremiumitem.m_ManaReducePotionValue / 100) +
				(lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] * 20 / 100))));
	}

	// Caso contrário, se apenas o tempo de poção de redução de mana estiver ativo...
	else if (chaPremiumitem.m_ManaReducePotiontime > 0)
	{
		// ...deduz a mana com a redução da poção.
		sinSetMana(sinGetMana() - (lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] - (lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] * chaPremiumitem.m_ManaReducePotionValue / 100)));
	}

	// Caso contrário, se o tempo de Terry e o scroll de gravidade estiverem ativos...
	else if (chaPremiumitem.m_TerryTime > 0 && sinChar->GravityScroolCheck[1] == 1)
	{
		// ...deduz a mana com a redução de 20%.
		sinSetMana(sinGetMana() - (lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] - (lpSkill->Skill_Info.UseMana[lpSkill->Point - 1] * 20 / 100)));
	}

	// Caso contrário (nenhum dos buffs de redução de mana está ativo)...
	else
	{
		// ...se a habilidade usar mana, deduz a mana total.
		if (lpSkill->Skill_Info.UseMana)
			sinSetMana(sinGetMana() - lpSkill->Skill_Info.UseMana[lpSkill->Point - 1]);
	}



	// Bloco de dedução de stamina.
	// Se a habilidade usar stamina (UseStamina[0] é diferente de zero)...
	if (lpSkill->Skill_Info.UseStamina[0])
	{
		// Se o tempo de poção de redução de stamina não estiver ativo...
		if (chaPremiumitem.m_StaminaReducePotiontime <= 0)
		{
			// ...deduz a stamina sem redução.
			sinSetStamina(sinGetStamina() - (lpSkill->Skill_Info.UseStamina[0] + (lpSkill->Skill_Info.UseStamina[1] * (lpSkill->Point - 1))));
		}
		// Caso contrário (o tempo de poção de redução de stamina está ativo)...
		else
		{
			// ...deduz a stamina com a redução da poção.
			sinSetStamina(sinGetStamina() - ((lpSkill->Skill_Info.UseStamina[0] + (lpSkill->Skill_Info.UseStamina[1] * (lpSkill->Point - 1)))
				- ((lpSkill->Skill_Info.UseStamina[0] + (lpSkill->Skill_Info.UseStamina[1] * (lpSkill->Point - 1))) * chaPremiumitem.m_StaminaReducePotionValue / 100)));
		}
	}

	// Verifica e reforma a maestria da habilidade.
	cSkill.CheckSkillMasteryForm(lpSkill);
	lpSkill->Mastery = 0; // Reinicia a maestria (possivelmente para ser recalculada).
	cSkill.ReformSkillMasteryForm(lpSkill);

	// Incrementa o contador de uso da habilidade.
	lpSkill->UseSKillIncreCount++;
	// Se o contador de uso atingir o limite para aumentar a maestria...
	if (lpSkill->UseSKillIncreCount >= sinMasteryIncreaIndex[lpSkill->Skill_Info.SkillNum] + ((lpSkill->Point - 1) / 3)) {
		// ...reinicia o contador e aumenta a contagem de uso da habilidade para maestria.
		lpSkill->UseSKillIncreCount = 0;
		lpSkill->UseSkillCount += USE_SKILL_MASTERY_COUNT;

	}

	return TRUE; // Retorna TRUE indicando sucesso.
}


// Função: sinContinueSkillSet
// Adiciona uma habilidade à lista de habilidades contínuas (buffs/debuffs).
// Parâmetros: lpSkill - Ponteiro para a estrutura da habilidade (sSKILL).
int sinContinueSkillSet(sSKILL* lpSkill)
{
	int i = 0;

	// Se a habilidade for SKILL_ENERGY_SHIELD, SKILL_COMPULSION ou SKILL_GOLDEN_FALCON...
	if (lpSkill->CODE == SKILL_ENERGY_SHIELD || lpSkill->CODE == SKILL_COMPULSION || lpSkill->CODE == SKILL_GOLDEN_FALCON)
	{
		// ...itera sobre as habilidades contínuas ativas.
		for (i = 0; i < MAX_CONTINUE_SKILL; i++)
		{
			// Se uma habilidade contínua estiver ativa...
			if (ContinueSkill[i].Flag)
			{
				// ...e for uma das habilidades listadas (Energy Shield, Compulsion, Golden Falcon)...
				if (ContinueSkill[i].CODE == SKILL_ENERGY_SHIELD || ContinueSkill[i].CODE == SKILL_COMPULSION || ContinueSkill[i].CODE == SKILL_GOLDEN_FALCON)
				{
					// ...limpa a entrada da habilidade contínua (remove o buff/debuff).
					memset(&ContinueSkill[i], 0, sizeof(sSKILL));
					break; // Sai do loop.
				}
			}
		}
	}

	// Itera sobre os slots de habilidades contínuas para encontrar um slot vazio.
	for (i = 0; i < MAX_CONTINUE_SKILL; i++) {
		// Se o slot não estiver em uso (Flag é 0)...
		if (!ContinueSkill[i].Flag) {
			// ...copia a nova habilidade para o slot.
			memcpy(&ContinueSkill[i], lpSkill, sizeof(sSKILL));
			ContinueSkill[i].Flag = 1; // Define a flag para indicar que o slot está em uso.
			cSkill.SearchSkillDoc(&ContinueSkill[i]); // Busca a documentação/informações da habilidade contínua.
			// Se a habilidade não for uma das habilidades que não possuem ícone de material...
			if ((lpSkill->CODE != CHAT_DELAY && lpSkill->CODE != QUEST_DIARY && lpSkill->CODE != SODCROWN_GOLD && lpSkill->CODE != SODCROWN_SILVER && lpSkill->CODE != BLESSCROWN_SILVER && lpSkill->CODE != BLESSCROWN_BRONZE && lpSkill->CODE != SODCROWN_BRONZE && lpSkill->CODE != SKILL_PVP_MODE && lpSkill->CODE != SKILL_TOP_LVL && lpSkill->CODE != SKILL_TOP_PVP && lpSkill->CODE != SKILL_FORCE_ORB && lpSkill->CODE != CHANGE_JOB3_QUEST && lpSkill->CODE != CHANGE_ELEMENTARY_QUEST &&
				lpSkill->CODE != BOOSTER_ITEM_LIFE && lpSkill->CODE != BOOSTER_ITEM_MANA && lpSkill->CODE != BOOSTER_ITEM_STAMINA))
				ContinueSkill[i].MatIcon = 0; // Define o ícone de material como 0 (não visível ou padrão).
			break; // Sai do loop após adicionar a habilidade.

		}
	}

	return TRUE; // Retorna TRUE indicando sucesso.
}

// Função: sinCheckContinueSkill
// Esta função parece ser um placeholder ou está incompleta, pois sempre retorna TRUE.
int sinCheckContinueSkill()
{












	return TRUE;
}



// Função: sinSwitchSkill
// Esta função parece ser um placeholder ou está incompleta, pois sempre retorna TRUE.
int sinSwitchSkill(sSKILL* pSkill)
{
































	return TRUE;
}






// Funções de Habilidades Individuais (F_NomeDaHabilidade)
// Estas funções representam o uso de habilidades específicas no jogo.
// A maioria delas chama sinUseManaStamina(pUseSkill) para deduzir o custo de mana/stamina.
// Algumas também chamam sinContinueSkillSet para adicionar a habilidade como um buff/debuff contínuo,
// sinSwitchSkill para lidar com habilidades que alternam estado, ou cInvenTory.SetItemToChar() para atualizar o inventário.

// Habilidade: F_Sword_Blast
int F_Sword_Blast()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina para a habilidade.
	return TRUE;
}
// Habilidade: F_HolyBody
int F_HolyBody()
{
	pUseSkill->UseTime = HolyBody_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Holy Body como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinSwitchSkill(pUseSkill); // Lida com a alternância da habilidade.
	return TRUE;
}
// Habilidade: F_Physical_Traning
int F_Physical_Traning()
{

	return TRUE; // Retorna TRUE, sem custo de mana/stamina ou efeito imediato aparente.
}
// Habilidade: F_Double_Crash
int F_Double_Crash()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}


// Habilidade: F_S_Strike
int F_S_Strike()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Farina
int F_Farina()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_D_Mastery
int F_D_Mastery()
{


	return TRUE; // Retorna TRUE, sem custo de mana/stamina ou efeito imediato aparente.
}
// Habilidade: F_V_Spear
int F_V_Spear()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}


// Habilidade: F_Healing
int F_Healing()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_HolyBolt
int F_HolyBolt()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_M_Spark
int F_M_Spark()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_HolyMind
int F_HolyMind()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}


// Habilidade: F_Agony
int F_Agony()
{
	short TempLife, TempLife2, TempMana; // Declara variáveis temporárias para vida e mana.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	// Calcula a vida temporária a ser deduzida com base na vida máxima e no valor de conversão de Agony.
	TempLife = (short)(((float)sinChar->Life[1] / 100.0f) * (float)Agony_ConvLife[pUseSkill->Point - 1]);
	// Calcula a mana temporária a ser adicionada com base na mana máxima e no valor de conversão de Agony.
	TempMana = (short)(((float)sinChar->Mana[1] / 100.0f) * (float)Agony_ConvLife[pUseSkill->Point - 1]);
	// Se a vida atual menos a vida temporária for maior que 0 (para evitar vida negativa)...
	if ((sinGetLife() - TempLife) > 0) {
		TempLife2 = sinGetLife() - TempLife; // Calcula a nova vida.
		sinSetLife(TempLife2); // Define a nova vida do personagem.
		TempMana = sinGetMana() + TempMana; // Calcula a nova mana (adiciona mana).
		sinSetMana(TempMana); // Define a nova mana do personagem.

	};




	return TRUE;
}
// Habilidade: F_FireBolt
int F_FireBolt()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Zenith
int F_Zenith()
{

	pUseSkill->UseTime = Zenith_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Zenith como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem (possivelmente para buffs de item).
	return TRUE;
}
// Habilidade: F_ZenithFromServer
// Esta função parece ser chamada quando o Zenith é ativado pelo servidor.
int F_ZenithFromServer(int Time)
{
	// Itera sobre os slots de habilidades contínuas.
	for (int i = 0; i < MAX_CONTINUE_SKILL; i++) {
		// Se o slot não estiver em uso...
		if (!ContinueSkill[i].Flag) {
			ContinueSkill[i].Flag = 1; // Define a flag para indicar que o slot está em uso.
			ContinueSkill[i].CODE = SKILL_ZENITH; // Define o código da habilidade como Zenith.
			ContinueSkill[i].Time[1] = Time; // Define o tempo de duração da habilidade.
			ContinueSkill[i].PartyFlag = 1; // Define a flag de grupo (possivelmente para buffs de grupo).
			break; // Sai do loop.

		}
	}
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_FireBall
int F_FireBall()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}




// Habilidade: F_Holy_Valor
int F_Holy_Valor()
{

	pUseSkill->UseTime = Holy_Valor_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Holy Valor como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinSwitchSkill(pUseSkill); // Lida com a alternância da habilidade.
	return TRUE;
}










// Habilidade: F_Brandish
int F_Brandish()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Piercing
int F_Piercing()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Drastic_Spirit
int F_Drastic_Spirit()
{
	pUseSkill->UseTime = Drastic_Spirit_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Drastic Spirit como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinSwitchSkill(pUseSkill); // Lida com a alternância da habilidade.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.
	return TRUE;
}

// Habilidade: F_Windy
int F_Windy()
{

	pUseSkill->UseTime = Windy_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Windy como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.
	return TRUE;
}

// Habilidade: F_Twist_Javelin
int F_Twist_Javelin()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Soul_Sucker
int F_Soul_Sucker()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Fire_Javelin
int F_Fire_Javelin()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}


// Habilidade: F_Meditation
int F_Meditation()
{
	return TRUE; // Retorna TRUE, sem custo de mana/stamina ou efeito imediato aparente.
}

// Habilidade: F_Divine_Lightning
int F_Divine_Lightning()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Holy_Reflection
int F_Holy_Reflection()
{
	pUseSkill->UseTime = Holy_Reflection_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Holy Reflection como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Grand_Healing
int F_Grand_Healing()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Mental_Mastery
int F_Mental_Mastery()
{
	return TRUE; // Retorna TRUE, sem custo de mana/stamina ou efeito imediato aparente.
}

// Habilidade: F_Watornado
int F_Watornado()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Enchant_Weapon
int F_Enchant_Weapon()
{



	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Dead_Ray
int F_Dead_Ray()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}





// Habilidade: F_S_Mastery
int F_S_Mastery()
{

	return TRUE; // Retorna TRUE, sem custo de mana/stamina ou efeito imediato aparente.
}

// Habilidade: F_D_Inhalation
int F_D_Inhalation()
{
	pUseSkill->UseTime = D_Inhalation_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona D_Inhalation como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	SwitchSkill(pUseSkill); // Lida com a alternância da habilidade.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.
	return TRUE;
}
// Habilidade: F_Holy_Incantation
int F_Holy_Incantation()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Grand_Cross
int F_Grand_Cross()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;

}


// Habilidade: F_Split_Javelin
int F_Split_Javelin()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_T_Of_Valhalla
int F_T_Of_Valhalla()
{


	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.



	// Se a habilidade não tiver um alvo específico...
	if (!pUseSkill->SkillTaget_CODE)
		SetT_Of_ValhallaFlag2 = 1; // Define uma flag específica para T_Of_Valhalla.


	return TRUE;
}
// Habilidade: F_Lightning_Javelin
int F_Lightning_Javelin()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Storm_Javelin
int F_Storm_Javelin()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}


// Habilidade: F_Vigor_Ball
int F_Vigor_Ball()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Resurrection
int F_Resurrection()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Extinction
int F_Extinction()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Virtual_Life
int F_Virtual_Life()
{


	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.


	return TRUE;
}


// Habilidade: F_Energy_Shield
int F_Energy_Shield()
{
	pUseSkill->UseTime = Energy_Shield_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Energy Shield como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Diastrophism
int F_Diastrophism()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Spirit_Elemental
int F_Spirit_Elemental()
{
	pUseSkill->UseTime = Spirit_Elemental_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Spirit Elemental como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.
	return TRUE;
}
// Habilidade: F_D_Sword
int F_D_Sword()
{
	pUseSkill->UseTime = Dancing_Sword_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Dancing Sword como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.
	return TRUE;
}




// Habilidade: F_Divine_Piercing
int F_Divine_Piercing()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Godly_Shield
int F_Godly_Shield()
{
	pUseSkill->UseTime = Godly_Shield_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Godly Shield como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	SwitchSkill(pUseSkill); // Lida com a alternância da habilidade.
	return TRUE;
}
// Habilidade: F_God_Bless
int F_God_Bless()
{
	pUseSkill->UseTime = God_Bless_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona God Bless como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.
	return TRUE;
}
// Habilidade: F_Sword_Of_Justice
int F_Sword_Of_Justice()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_S_Breaker
int F_S_Breaker()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}


// Habilidade: F_C_Moon
int F_C_Moon()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}


// Habilidade: F_S_Blade
int F_S_Blade()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_H_Benedic
int F_H_Benedic()
{
	pUseSkill->UseTime = H_Benedic_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona H_Benedic como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.
	return TRUE;
}

// Habilidade: F_Hall_Of_Valhalla
int F_Hall_Of_Valhalla()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_X_Rage
int F_X_Rage()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Frost_Javelin
int F_Frost_Javelin()
{
	pUseSkill->UseTime = Frost_Javelin_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Frost Javelin como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.
	return TRUE;
}
// Habilidade: F_Vengeance
int F_Vengeance()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Talaria
int F_Talaria()
{
	pUseSkill->UseTime = Talaria_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Talaria como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.
	return TRUE;
}

// Habilidade: F_G_Coup
int F_G_Coup()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Arcuda
int F_Arcuda()
{
	pUseSkill->UseTime = 360; // Define o tempo de duração da habilidade (360 unidades de tempo).
	sinContinueSkillSet(pUseSkill); // Adiciona Arcuda como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.
	SummonSkillCodeIndex[3] = 0; // Reinicia um índice de código de habilidade de invocação.
	return TRUE;
}

// Habilidade: F_S_Fear
int F_S_Fear()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Glacial_Spike
int F_Glacial_Spike()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Regeneration_Field
int F_Regeneration_Field()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Chain_Lightning
int F_Chain_Lightning()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Summon_Muspell
int F_Summon_Muspell()
{
	pUseSkill->UseTime = Summon_Muspell_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinContinueSkillSet(pUseSkill); // Adiciona Summon Muspell como habilidade contínua.
	return TRUE;
}

// Habilidade: F_S_Impact
int F_S_Impact()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_P_Ice
int F_P_Ice()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Summon_Ramiel
int F_Summon_Ramiel()
{
	pUseSkill->UseTime = Summon_Ramiel_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinContinueSkillSet(pUseSkill); // Adiciona Summon Ramiel como habilidade contínua.
	return TRUE;
}

// Habilidade: F_Krishna
int F_Krishna()
{
	pUseSkill->UseTime = Krishna_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinContinueSkillSet(pUseSkill); // Adiciona Krishna como habilidade contínua.
	cInvenTory.SetItemToChar();
	return TRUE;
}

// Habilidade: F_Fire_Elemental
int F_Fire_Elemental()
{
	pUseSkill->UseTime = 6 * 60;; // Define o tempo de duração da habilidade (6 minutos).
	sinContinueSkillSet(pUseSkill); // Adiciona Fire Elemental como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	SummonSkillCodeIndex[1] = 0; // Reinicia um índice de código de habilidade de invocação.
	return TRUE;
}
// Habilidade: F_Flame_Wave
int F_Flame_Wave()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}
// Habilidade: F_Distortion
int F_Distortion()
{
	pUseSkill->UseTime = Distortion_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.


	return TRUE;
}
// Habilidade: F_Meteo
int F_Meteo()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Silraphim
int F_Silraphim()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Tenus
int F_Tenus()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Ignis
int F_Ignis()
{
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Anima
int F_Anima()
{
	pUseSkill->UseTime = Anima_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinContinueSkillSet(pUseSkill); // Adiciona Anima como habilidade contínua.
	return TRUE;
}

// Habilidade: F_DarkBolt
int F_DarkBolt()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}


// Habilidade: F_DarkWave
int F_DarkWave()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_CurseLazy
int F_CurseLazy()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_SpiritualFlare
int F_SpiritualFlare()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_SoulManacle
int F_SoulManacle()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_ChasingHunt
int F_ChasingHunt()
{
	pUseSkill->UseTime = ChasingHunt_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Chasing Hunt como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinSwitchSkill(pUseSkill); // Lida com a alternância da habilidade.

	return TRUE;
}

// Habilidade: F_AdventMigal
int F_AdventMigal()
{
	pUseSkill->UseTime = AdventMigal_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Advent Migal como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinSwitchSkill(pUseSkill); // Lida com a alternância da habilidade.

	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.

	return TRUE;
}

// Habilidade: F_LandGhost
int F_LandGhost()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_RainMaker
int F_RainMaker()
{
	pUseSkill->UseTime = RainMaker_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Rain Maker como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinSwitchSkill(pUseSkill); // Lida com a alternância da habilidade.

	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.

	return TRUE;

}

// Habilidade: F_Haunt
int F_Haunt()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}


// Habilidade: F_Scratch
int F_Scratch()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_RBloodyKnight
int F_RBloodyKnight()
{

	pUseSkill->UseTime = BloodyKnight_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Bloody Knight como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinSwitchSkill(pUseSkill); // Lida com a alternância da habilidade.
	SummonSkillCodeIndex[3] = 0; // Reinicia um índice de código de habilidade de invocação.

	return TRUE;
}

// Habilidade: F_Judgement
int F_Judgement()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_AdventMidranda
int F_AdventMidranda()
{
	pUseSkill->UseTime = AdventMidranda_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Advent Midranda como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinSwitchSkill(pUseSkill); // Lida com a alternância da habilidade.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.
	return TRUE;
}

// Habilidade: F_MourningOfPray
int F_MourningOfPray()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_Creed
int F_Creed()
{
	pUseSkill->UseTime = Creed_Time[pUseSkill->Point - 1]; // Define o tempo de duração da habilidade.
	sinContinueSkillSet(pUseSkill); // Adiciona Creed como habilidade contínua.
	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	sinSwitchSkill(pUseSkill); // Lida com a alternância da habilidade.
	cInvenTory.SetItemToChar(); // Atualiza o inventário do personagem.
	return TRUE;
}

// Habilidade: F_P_Deity
int F_P_Deity()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_G_Nail
int F_G_Nail()
{

	sinUseManaStamina(pUseSkill); // Deduz mana/stamina.
	return TRUE;
}

// Habilidade: F_H_Regene
int F_H_Regene()
{
	return TRUE; // Retorna TRUE, sem custo de mana/stamina ou efeito imediato aparente.
}

