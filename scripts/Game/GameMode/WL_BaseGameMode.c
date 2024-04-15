class WL_BaseGameModeClass : SCR_BaseGameModeClass {}

class WL_BaseGameMode : SCR_BaseGameMode {
	[Attribute()]
	protected ref array<ref WL_ItemSpawnerConfig> m_aSpawnerConfigs;
	
	void GetItemSpawnerResourceNames(WL_EItemSpawnerType pType, out notnull array<ResourceName> resourceNames) {
		WL_ItemSpawnerConfig foundConfig = null;
		foreach (WL_ItemSpawnerConfig config : m_aSpawnerConfigs) {
			if (config.m_eForType == pType)
				foundConfig = config;
		}
		
		if (!foundConfig) {
			Print("Item spawner config not found for type: " + pType, LogLevel.ERROR);
			return;
		}
		
		foreach (ResourceName prefab : foundConfig.m_aPrefabs)
			resourceNames.Insert(prefab);
	}
}