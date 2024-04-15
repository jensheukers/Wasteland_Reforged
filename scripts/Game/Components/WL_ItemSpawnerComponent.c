class WL_ItemSpawnerComponentClass : ScriptComponentClass {}

class WL_ItemSpawnerComponent : ScriptComponent {
	[Attribute("0", UIWidgets.ComboBox, enums: ParamEnumArray.FromEnum(WL_EItemSpawnerType))]
	protected WL_EItemSpawnerType m_eSpawnerType;
	
	protected void SpawnItem(ResourceName resourceName) {
		if (resourceName.IsEmpty())
			return;
		
		EntitySpawnParams p = new EntitySpawnParams();
		p.TransformMode = ETransformMode.WORLD;
        p.Transform[3] = GetOwner().GetOrigin();
		
		GetGame().SpawnEntityPrefab(Resource.Load(resourceName), null, p)
	}
	
	protected ResourceName GetRandomSpawnItemName() {
		WL_BaseGameMode gamemode = WL_BaseGameMode.Cast(GetGame().GetGameMode());
		
		array<ResourceName> prefabs = new array<ResourceName>();
		gamemode.GetItemSpawnerResourceNames(m_eSpawnerType, prefabs);
		if (prefabs.Count() <= 0)
			return "";
		
		return prefabs[Math.RandomInt(0, prefabs.Count())];
	}
	
	override void OnPostInit(IEntity owner) {
		if (!Replication.IsServer())
			return;
		
		SetEventMask(owner, EntityEvent.INIT);
	}
	
	override void EOnInit(IEntity owner) {
		SpawnItem(GetRandomSpawnItemName());
	}
}