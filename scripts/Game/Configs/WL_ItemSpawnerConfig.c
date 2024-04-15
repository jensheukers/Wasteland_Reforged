enum WL_EItemSpawnerType {
	WEAPONS_PISTOLS,
	WEAPONS_RIFLES,
	WEAPONS_EXPLOSIVES,
	WEAPONS_GRENADES,
	WEAPONS_AMMO,
	
	MEDICAL,
	TOOLS,
	EQUIPMENT,
	
	HEADGEAR,
	CLOTHING,
	VEST
}

[BaseContainerProps(configRoot: true)]
class WL_ItemSpawnerConfig {
	[Attribute("0", UIWidgets.ComboBox, enums: ParamEnumArray.FromEnum(WL_EItemSpawnerType))]
	WL_EItemSpawnerType m_eForType;
	
	[Attribute("", UIWidgets.ResourceNamePicker, "Choose prefab", "et")]
	ref array<ResourceName> m_aPrefabs;
}