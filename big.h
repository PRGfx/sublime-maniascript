class Void {};
class Integer{};
class Real{};
class Boolean{};
class Text{};
class Vec2{};
class Vec3{};
class Int3{};
class Ident{};

struct CMlScript : public CNod {
      enum LinkType {
              ExternalBrowser,
              ManialinkBrowser,
              Goto,
              ExternalFromId,
              ManialinkFromId,
              GotoFromId,
      };
      const   CMlPage Page;
      const   Boolean PageIsVisible;
      const   Integer Now;
      const   Integer Period;
      const   Integer CurrentTime;
      const   Text CurrentTimeText;
      const   Text CurrentLocalDateText;
      const   CUser LocalUser;
      const   CTitle LoadedTitle;
      const   CMlEvent[] PendingEvents;
      const   Real MouseX;
      const   Real MouseY;
      const   Boolean MouseLeftButton;
      const   Boolean MouseRightButton;
      const   Boolean MouseMiddleButton;
      const   Boolean KeyUp;
      const   Boolean KeyDown;
      const   Boolean KeyLeft;
      const   Boolean KeyRight;
     const   Boolean KeyReturn;
     const   Boolean KeySpace;
     const   Boolean KeyDelete;
                     Boolean IsKeyPressed(Integer KeyCode);
                     Boolean EnableMenuNavigationInputs;
                     Void EnableMenuNavigation(Boolean EnableInputs,Boolean WithAutoFocus,CMlControl AutoBackControl,Integer InputPriority);
     const   Boolean IsMenuNavigationForeground;
                     Void OpenLink(Text Url,LinkType LinkType);
                     Void TriggerPageAction(Text ActionString);
     const   CXmlManager Xml;
     const   CHttpManager Http;
     const   CAudioManager Audio;
                     Void SendCustomEvent(Text Type,Text[] Data);
                     Void PreloadImage(Text ImageUrl);
};

struct CMlEntry : public CMlControl {
                     Text Value;
                     Void StartEdition();
                     Integer MaxLine;
                     Boolean AutoNewLine;
};

struct CMlFileEntry : public CMlEntry {
     const   Text FullFileName;
};

struct CMlLabel : public CMlControl {
                     Text Style;
                     Text Substyle;
                     Text TextFont;
                     Void SetText(Text NewText);
                     Text Value;
     const   Integer ValueLineCount;
                     Integer MaxLine;
                     Boolean AppendEllipsis;
                     Boolean AutoNewLine;
                     Real Opacity;
                     Vec3 TextColor;
                     Integer TextSize;
                     Real ComputeWidth(Text Text);
};

struct CMlMediaPlayer : public CMlControl {
};

struct CMlQuad : public CMlControl {
     enum EKeepRatioMode {
             Inactive,
             Clip,
             Fit,
     };
                     Void ChangeImageUrl(Text fieldName);
                     Text ImageUrl;
                     Text ImageUrlFocus;
                     Text Style;
                     Text Substyle;
                     Boolean StyleSelected;
     const   Boolean DownloadInProgress;
                     Vec3 Colorize;
                     Vec3 ModulateColor;
                     Vec3 BgColor;
                     Vec3 BgColorFocus;
                     Real Opacity;
                     EKeepRatioMode KeepRatio;
};

struct CMlGauge : public CMlControl {
                     Text Style;
                     Void SetRatio(Real NewRatio);
                     Void SetClan(Integer NewClan);
                     Real Ratio;
                     Real GradingRatio;
                     Integer Clan;
                     Vec3 Color;
                     Boolean DrawBackground;
                     Boolean DrawBlockBackground;
                     Boolean CenteredBar;
};

struct CMlGraph : public CMlControl {
                     Vec2 CoordsMin;
                     Vec2 CoordsMax;
                     CMlGraphCurve AddCurve();
                     Void RemoveCurve(CMlGraphCurve Curve);
                     CMlGraphCurve[] Curves;
};

struct CMlMinimap : public CMlControl {
                     Vec3 WorldPosition;
                     Vec2 MapPosition;
                     Real MapYaw;
                     Real ZoomFactor;
};

struct CMlCamera : public CMlControl {
};

struct CMlBrowser : public CMlScript {
     enum EBuddyAction {
             Add,
             Invite,
             Remove,
     };
     enum EBuddyResult {
             Ok,
             Error,
             NotFinished,
     };
     const   CMap CurMap;
                     Void ShowCurMapCard();
     const   EBuddyResult BuddyDoResult;
     const   Text BuddyDoErrorMessage;
     const   Boolean IsInBrowser;
                     Void BrowserBack();
                     Void BrowserQuit();
                     Void BrowserHome();
                     Void BrowserReload();
                     Text BrowserFocusedFrameId;
                     Void SetLocalUserClubLink(Text ClubLink);
};

struct CManiaApp : public CNod {
     enum ELinkType {
             ExternalBrowser,
             ManialinkBrowser,
     };
     const   Integer Now;
     const   Boolean IsVisible;
     const   CUser LocalUser;
     const   CTitle LoadedTitle;
                     Boolean EnableMenuNavigationInputs;
     const   Real MouseX;
     const   Real MouseY;
     const   CUILayer[] UILayers;
                     CUILayer UILayerCreate();
                     Void UILayerDestroy(CUILayer Layer);
                     Void UILayerDestroyAll();
                     Void LayerCustomEvent(CUILayer Layer,Text Type,Text[] Data);
                     Void OpenLink(Text Url,ELinkType LinkType);
     const   CXmlManager Xml;
     const   CHttpManager Http;
     const   CAudioManager Audio;
};

struct CManiaAppEvent : public CNod {
     enum EType {
             LayerCustomEvent,
             KeyPress,
             ExternalCustomEvent,
             MenuNavigation,
     };
     enum EMenuNavAction {
             Up,
             Right,
             Left,
             Down,
             Select,
             Cancel,
             PageUp,
             PageDown,
     };
     const   EType Type;
     const   CUILayer CustomEventLayer;
     const   Text CustomEventType;
     const   Text[] CustomEventData;
     const   Text ExternalEventType;
     const   Text[] ExternalEventData;
     const   EMenuNavAction MenuNavAction;
     const   Integer KeyCode;
     const   Text KeyName;
};

struct CManiaAppTitle : public CManiaApp {
     const   CManiaAppEvent[] PendingEvents;
                     Void Menu_Quit();
                     Void Menu_Home();
                     Void Menu_Solo();
                     Void Menu_Competitions();
                     Void Menu_Local();
                     Void Menu_Internet();
                     Void Menu_Editor();
                     Void Menu_Profile();
                     Void PlayMap(Text Map);
                     Boolean LoadingScreenRequireKeyPressed;
                     Boolean DontScaleMainMenuForHMD;
};

struct CStation : public CNod {
     const   CTitle Title;
     const   Integer AudienceRegisteredUsers;
     const   Integer CampaignMedalsMax;
     const   Integer CampaignMedalsCurrent;
     const   Integer CampaignMedalsRanking;
     const   Real LadderPoints;
     const   Integer LadderRank;
};

struct CMlStation : public CMlBrowser {
     const   CStation Station;
                     Void EnterStation();
};

struct CEditorPlugin : public CManiaApp {
     enum CardinalDirections {
             North,
             East,
             South,
             West,
     };
     enum PlaceMode {
             Unknown,
             Terraform,
             Block,
             Macroblock,
             Skin,
             CopyPaste,
             Test,
             Plugin,
             CustomSelection,
             OffZone,
             BlockProperty,
             Path,
             GhostBlock,
     };
     enum EditMode {
             Unknown,
             Place,
             FreeLook,
             Erase,
             Pick,
             SelectionAdd,
             SelectionRemove,
     };
     const   CEditorPluginEvent[] PendingEvents;
     const   CMap Map;
                     Void ComputeShadows();
                     Void Undo();
                     Void Redo();
                     Void Quit();
                     Void Help();
                     Void Validate();
                     Void AutoSave();
                     Void SaveMap(Text FileName,Text Path);
                     PlaceMode PlaceMode;
                     EditMode EditMode;
                     Boolean UndergroundMode;
                     Boolean BlockStockMode;
                     Int3 CursorCoord;
                     CardinalDirections CursorDir;
                     CBlockModel CursorBlockModel;
                     CBlockModel CursorTerrainBlockModel;
                     CMacroblockModel CursorMacroblockModel;
                     Real CameraVAngle;
                     Real CameraHAngle;
                     Real CameraToTargetDistance;
                     Vec3 TargetedPosition;
                     Boolean EnableAirMapping;
                     Boolean EnableMixMapping;
                     Void RemoveAllBlocks();
                     Void RemoveAllTerrain();
                     Void RemoveAllOffZone();
                     Void RemoveAllObjects();
                     Void RemoveAll();
                     Void RemoveAllBlocksAndTerrain();
                     Void ShowCustomSelection();
                     Void HideCustomSelection();
                     Void CopyPaste_Copy();
                     Void CopyPaste_Cut();
                     Void CopyPaste_Remove();
                     Void CopyPaste_SelectAll();
                     Void CopyPaste_ResetSelection();
                     Void OpenToolsMenu();
                     Void EditMediatrackIngame();
                     Boolean CanPlaceBlock(CBlockModel BlockModel,Int3 Coord,CardinalDirections Dir,Boolean OnGround,Integer VariantIndex);
                     Boolean PlaceBlock(CBlockModel BlockModel,Int3 Coord,CardinalDirections Dir);
                     Boolean CanPlaceBlock_NoDestruction(CBlockModel BlockModel,Int3 Coord,CardinalDirections Dir,Boolean OnGround,Integer VariantIndex);
                     Boolean PlaceBlock_NoDestruction(CBlockModel BlockModel,Int3 Coord,CardinalDirections Dir);
                     Boolean CanPlaceRoadBlocks(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
                     Boolean PlaceRoadBlocks(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
                     Boolean CanPlaceTerrainBlocks(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
                     Boolean PlaceTerrainBlocks(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
                     Boolean PlaceTerrainBlocks_NoDestruction(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
                     Boolean CanPlaceMacroblock(CMacroblockModel BlockModel,Int3 Coord,CardinalDirections Dir);
                     Boolean PlaceMacroblock(CMacroblockModel BlockModel,Int3 Coord,CardinalDirections Dir);
                     Boolean CanPlaceMacroblock_NoDestruction(CMacroblockModel BlockModel,Int3 Coord,CardinalDirections Dir);
                     Boolean PlaceMacroblock_NoDestruction(CMacroblockModel BlockModel,Int3 Coord,CardinalDirections Dir);
                     CBlock GetBlock(Int3 Coord);
                     Boolean RemoveBlock(Int3 Coord);
                     Boolean RemoveTerrainBlocks(Int3 StartCoord,Int3 EndCoord);
                     Integer GetBlockGroundHeight(CBlockModel BlockModel,Integer CoordX,Integer CoordZ,CardinalDirections Dir);
                     CBlock GetStartLineBlock();
                     Void CopyPaste_AddOrSubSelection(Int3 StartCoord,Int3 EndCoord);
                     Boolean CopyPaste_Symmetrize();
                    Void SaveMacroblock(CMacroblockModel MacroblockModel);
                    Integer GetInterfaceNumber(CCollector Collector);
                    Void SetInterfaceNumber(CCollector Collector,Integer NewValue);
                    CMacroblockModel GetMacroblockModelFromName(Text MacroblockModelName);
                    CBlockModel GetTerrainBlockModelFromName(Text TerrainBlockModelName);
                    CBlockModel GetBlockModelFromName(Text BlockModelName);
    const   CItemAnchor[] Items;
    const   Text[] MediatrackIngameClips;
    const   Text[] MediatrackIngameIsScriptClips;
                    Integer MediatrackIngameEditedClipIndex;
    const   CBlock[] Blocks;
    const   CBlockModel[] BlockModels;
    const   CBlockModel[] TerrainBlockModels;
    const   CMacroblockModel[] MacroblockModels;
    const   CAnchorData[] AnchorData;
                    Int3[] CustomSelectionCoords;
                    Vec3 CustomSelectionRGB;
                    Boolean EnableEditorInputsCustomProcessing;
    const   Boolean EditorInputIsDown_Menu;
    const   Boolean EditorInputIsDown_SwitchToRace;
    const   Boolean EditorInputIsDown_CursorUp;
    const   Boolean EditorInputIsDown_CursorRight;
    const   Boolean EditorInputIsDown_CursorDown;
    const   Boolean EditorInputIsDown_CursorLeft;
    const   Boolean EditorInputIsDown_CursorRaise;
    const   Boolean EditorInputIsDown_CursorLower;
    const   Boolean EditorInputIsDown_CursorTurn;
    const   Boolean EditorInputIsDown_CursorPick;
    const   Boolean EditorInputIsDown_CursorPlace;
    const   Boolean EditorInputIsDown_CursorDelete;
    const   Boolean EditorInputIsDown_CameraUp;
    const   Boolean EditorInputIsDown_CameraRight;
    const   Boolean EditorInputIsDown_CameraDown;
    const   Boolean EditorInputIsDown_CameraLeft;
    const   Boolean EditorInputIsDown_IconUp;
    const   Boolean EditorInputIsDown_IconRight;
    const   Boolean EditorInputIsDown_IconDown;
    const   Boolean EditorInputIsDown_IconLeft;
    const   Real CollectionSquareSize;
    const   Real CollectionSquareHeight;
    const   Integer CollectionGroundY;
                    Text ManialinkText;
    const   CMlPage ManialinkPage;
};

struct CSmMode : public CMode {
    enum EWeapon {
            Laser,
            Rocket,
            Nucleus,
            Arrow,
    };
    enum EActionSlot {
            Slot_A,
            Slot_B,
            Slot_C,
            Slot_D,
            Slot_E,
            Slot_F,
            Slot_G,
            Slot_H,
    };
    enum EActionInput {
            Weapon,
            Movement,
            Activable1,
            Activable2,
            Activable3,
            Activable4,
            Consumable1,
            Consumable2,
            None,
    };
    enum EGameplay {
            Default,
            Mp3Beta0,
    };
                    Integer StartTime;
                    Integer EndTime;
                    Integer SpawnInvulnerabilityDuration;
                    Boolean UseClans;
                    Boolean UseForcedClans;
                    Boolean UsePvPCollisions;
                    Boolean UsePvPWeapons;
                    Boolean UseInterractiveScreensIn3d;
                    Boolean UseLaserVsBullets;
                    Boolean UseLaserSkewering;
                    Boolean UsePlayerTagging;
                    Boolean UseBeaconsWithRecipients;
                    Boolean UseAmmoBonusOnHit;
                    Boolean UseSameWallJump;
                    Boolean UseDefaultActionEvents;
                    Boolean UseAllies;
                    Boolean UseAutoSpawnBots;
                    Boolean ForceNavMapsComputation;
                    Integer GameplayVersion;
                    EGameplay Gameplay;
                    Boolean UseProtectClanmates;
                    Real OffZoneRadius;
                    Real OffZoneRadiusSpeed;
                    Ident OffZoneCenterLandmarkId;
    const   Integer PlayersNbTotal;
    const   Integer PlayersNbAlive;
    const   Integer PlayersNbDead;
    const   Integer ClansNbTotal;
    const   Integer ClansNbAlive;
    const   Integer ClansNbDead;
    const   Integer[] ClansNbPlayers;
    const   Integer[] ClansNbPlayersAlive;
    const   CSmPlayer[] Players;
    const   CSmPlayer[] BotPlayers;
    const   CSmPlayer[] Spectators;
    const   CSmPlayer[] AllPlayers;
    const   CSmModeEvent[] PendingEvents;
    const   CSmMapBase[] MapBases;
    const   CSmMapLandmark[] MapLandmarks;
    const   CSmMapLandmark[] MapLandmarks_PlayerSpawn;
    const   CSmMapLandmark[] MapLandmarks_Gauge;
    const   CSmMapLandmark[] MapLandmarks_BotPath;
    const   CSmMapLandmark[] MapLandmarks_ObjectAnchor;
    const   CSmMapLandmark[] MapLandmarks_Gate;
    const   CSmScore[] Scores;
                    Integer[] ClanScores;
                    Void PassOn(CSmModeEvent Event);
                    Void Discard(CSmModeEvent Event);
                    Void SpawnPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CSmMapPlayerSpawn PlayerSpawn,Integer ActivationDate);
                    Void SpawnBotPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CSmMapPlayerSpawn PlayerSpawn,Integer ActivationDate);
                    Void SpawnBotPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CSmMapBotPath BotPath,Integer ActivationDate);
                    Void UnspawnPlayer(CSmPlayer Player);
                    Void ClearScores();
                    Void SetPlayerClan(CSmPlayer Player,Integer ClanNum);
                    Void SetPlayerWeapon(CSmPlayer Player,EWeapon DefaultWeapon,Boolean AutoSwitchWeapon);
                    Void SetPlayerReloadAllWeapons(CSmPlayer Player,Boolean ReloadAllWeapons);
                    Void SetPlayerAmmo(CSmPlayer Player,EWeapon Weapon,Integer Count);
                    Integer GetPlayerAmmo(CSmPlayer Player,EWeapon Weapon);
                    Void AddPlayerAmmo(CSmPlayer Player,EWeapon Weapon,Real DeltaCount);
                    Void SetPlayerAmmoMax(CSmPlayer Player,EWeapon Weapon,Integer Count);
                    Integer GetPlayerAmmoMax(CSmPlayer Player,EWeapon Weapon);
                    Void AddPlayerArmor(CSmPlayer Victim,Integer DeltaArmor,CSmPlayer Shooter,Integer ShooterPoints);
                    Void RemovePlayerArmor(CSmPlayer Victim,Integer DeltaArmor,CSmPlayer Shooter,Integer ShooterPoints);
                    Integer GetWeaponNum(EWeapon Weapon);
                    Boolean CanRespawnPlayer(CSmPlayer Player);
                    Void RespawnPlayer(CSmPlayer Player);
                    Void RespawnPlayer(CSmPlayer Player,CSmMapLandmark CheckpointLandmark);
                    CSmPlayer CreateBotPlayer(Ident ModelId,Integer TeamNum);
                    Void DestroyBotPlayer(CSmPlayer BotPlayer);
                    Void DestroyAllBotPlayers();
                    Void ScriptedBot_Move(CSmPlayer BotPlayer,Vec3 Goal);
                    Void ScriptedBot_MoveDelta(CSmPlayer BotPlayer,Vec3 Delta);
                    Void ScriptedBot_MoveAndAim(CSmPlayer BotPlayer,Vec3 Goal);
                    Void ScriptedBot_MoveDeltaAndAim(CSmPlayer BotPlayer,Vec3 Delta);
                    Void ScriptedBot_Aim(CSmPlayer BotPlayer,Vec3 Goal);
                    Void ScriptedBot_AimDelta(CSmPlayer BotPlayer,Real DeltaYaw,Real DeltaPitch);
                    Void ScriptedBot_RequestAction(CSmPlayer BotPlayer);
                    Void ScriptedBot_RequestGunTrigger(CSmPlayer BotPlayer);
                    Void ActionLoad(CSmPlayer Player,EActionSlot ActionSlot,Ident ModelId);
                    Void ActionBind(CSmPlayer Player,EActionSlot ActionSlot,EActionInput ActionInput);
                    Void ActionSetVariant(CSmPlayer Player,EActionSlot ActionSlot,Integer ActionVariant);
                    Void SetNbFakePlayers(Integer NbClan1,Integer NbClan2);
    const   CSmObject[] Objects;
                    CSmObject ObjectCreate(Ident ModelId);
                    Void ObjectDestroy(CSmObject Object);
                    Void ObjectDestroyAll();
                    Void Replay_SaveAttackScore(CSmPlayer Player,Integer Score);
                    Void Replay_SaveDefenseScore(CSmPlayer Player,Integer Score);
                    Void Replay_SaveTeamScore(Integer Team,Integer Score);
                    Void Replay_SavePlayerOfInterest(CSmPlayer Player);
                    Void Replay_SaveWinner(CSmPlayer Player);
                    Void Replay_SaveInterface();
};

struct CSmMlScriptIngame : public CMlScriptIngame {
    const   Integer ArenaNow;
    const   CSmPlayer InputPlayer;
    const   CSmPlayer GUIPlayer;
    const   CSmPlayer[] Players;
    const   CSmScore[] Scores;
    const   Integer[] ClanScores;
                    Boolean HideResumePlayingButton;
    const   CSmMapBase[] MapBases;
    const   CSmMapLandmark[] MapLandmarks;
    const   CSmMapLandmark[] MapLandmarks_PlayerSpawn;
    const   CSmMapLandmark[] MapLandmarks_Gauge;
    const   CSmMapLandmark[] MapLandmarks_BotPath;
    const   CSmMapLandmark[] MapLandmarks_ObjectAnchor;
    const   CSmMapLandmark[] MapLandmarks_Gate;
};

struct CSmAction : public CNod {
    const   Integer Now;
    const   Integer Variant;
                    CSmPlayer[] Players;
                    CSmPlayer Owner;
    const   Boolean IsActive;
                    Integer Energy;
                    Integer EnergyMax;
                    Integer EnergyCost;
                    Boolean EnergyReload;
    const   CSmActionEvent[] PendingEvents;
                    Void SendRulesEvent(Text Param1,Text[] Param2,CSmPlayer Shooter,CSmPlayer Victim);
                    Ident GetAnimModelId(Text ModelName);
                    Void PlayAnimOnPlayer(Ident AnimModelId,CSmPlayer Player);
                    Void PlayAnimAtPosition(Ident AnimModelId,Vec3 Position,Vec3 Direction);
                    Ident GetProjectileModelId(Text ModelName);
1710                         Void CreateProjectile(CSmPlayer PlayerToIgnore,Ident ProjectileModelId,Vec3 InitialPosition,Vec3 InitialDirection,Vec3;
1714                         Void CreateProjectile(CSmPlayer PlayerToIgnore,Ident ProjectileModelId,Vec3 InitialPosition,Vec3 InitialDirection,Vec3Integer ContextId);
                    Void CreateShoot(CSmPlayer Shooter,Ident ProjectileModelId);
                    Void CreateShoot(CSmPlayer Shooter,Ident ProjectileModelId,Integer ContextId);
                    Integer Cooldown;
                    Boolean Cooldown_IsReady(Integer Now);
                    Void Cooldown_Start();
};

struct CSmMapType : public CMapType {
    const   CSmMode Mode;
};

struct CTmMlScriptIngame : public CMlScriptIngame {
    const   CTmMlPlayer InputPlayer;
    const   CTmMlPlayer GUIPlayer;
    const   CTmMlPlayer[] Players;
    const   CTmScore[] Scores;
    const   Integer[] ClanScores;
    const   Vec3 MapStartLinePos;
    const   Vec3[] MapCheckpointPos;
    const   Vec3[] MapFinishLinePos;
    const   Boolean MapIsLapRace;
    const   Integer MapNbLaps;
};

struct CTmMode : public CMode {
    enum ETmScoreSortOrder {
            TotalPoints,
            BestRace_Time,
            BestRace_Stunts,
            BestRace_NbRespawns,
            BestRace_CheckpointsProgress,
            PrevRace_Time,
            Name,
            LadderRankSortValue,
    };
    enum ETMRespawnBehaviour {
            Normal,
            DoNothing,
            GiveUpBeforeFirstCheckPoint,
            AlwaysGiveUp,
    };
    enum ETmRaceChronoBehaviour {
            Auto,
            Hidden,
            CountDown,
            Normal,
    };
    enum EPersonalGhost {
            Disabled,
            Latest,
            FastestRace,
    };
    const   CTmPlayer[] AllPlayers;
    const   CTmPlayer[] Spectators;
    const   CTmPlayer[] Players;
    const   CTmPlayer[] PlayersRacing;
    const   CTmPlayer[] PlayersWaiting;
    const   CTmScore[] Scores;
                    Integer Clan1Score;
                    Integer Clan2Score;
                    Integer[] ClanScores;
    const   Integer ClansNbTotal;
    const   Integer[] ClansNbPlayers;
    const   CTmModeEvent[] PendingEvents;
                    Void PassOn(CTmModeEvent Event);
                    Void Discard(CTmModeEvent Event);
                    Void SpawnPlayer(CTmPlayer Player,Integer ClanNum,Integer RaceStartTime);
                    Void UnspawnPlayer(CTmPlayer Player);
                    Void SetPlayerClan(CTmPlayer Player,Integer ClanNum);
                    Void Scores_Sort(ETmScoreSortOrder SortOrder);
                    Void Scores_Clear();
                    Void Ladder_ComputeRank(ETmScoreSortOrder SortOrder);
                    Integer CutOffTimeLimit;
                    Integer NbLaps;
                    Boolean IndependantLaps;
                    Boolean UseClans;
                    Boolean UseForcedClans;
                    ETMRespawnBehaviour RespawnBehaviour;
                    Boolean UiRounds;
                    Boolean UiLaps;
                    Boolean UiStuntsMode;
                    Boolean UiDisplayStuntsNames;
                    Boolean UiDisableHelpMessage;
                    Integer UiScoresPointsLimit;
                    ETmRaceChronoBehaviour UiRaceChrono;
                    Boolean HideOpponents;
                    Integer ForceMaxOpponents;
                    Boolean EnableLegacyXmlRpcCallbacks;
                    Boolean MedalGhost_ShowGold;
                    Boolean MedalGhost_ShowSilver;
                    Boolean MedalGhost_ShowBronze;
                    EPersonalGhost PersonalGhost;
    const   Vec3 MapStartLinePos;
    const   Vec3[] MapCheckpointPos;
    const   Vec3[] MapFinishLinePos;
    const   Boolean MapIsLapRace;
    const   Integer MapNbLaps;
};

struct CTmMapType : public CMapType {
    const   CTmMode Mode;
};

struct CNod {
    const   Ident Id;
};

struct CMlPage : public CNod {
    const   CMlFrame MainFrame;
                    CMlControl GetFirstChild(Text ControlId);
                    Boolean LinksInhibited;
                    Void GetClassChildren(Text Class,CMlFrame Frame,Boolean Recursive);
    const   CMlControl[] GetClassChildren_Result;
};

struct CUser : public CNod {
    enum EEchelon {
            None,
            Bronze1,
            Bronze2,
            Bronze3,
            Silver1,
            Silver2,
            Silver3,
            Gold1,
            Gold2,
            Gold3,
    };
    enum ETagType {
            Bronze,
            Silver,
            Gold,
            Nadeo,
    };
    enum EStereoDisplayMode {
            None,
            Stereo,
            HMD,
    };
    const   Text Login;
    const   Text Name;
    const   Text AvatarUrl;
    const   Text ZonePath;
    const   Text ZoneFlagUrl;
    const   Text CountryFlagUrl;
    const   Text Language;
    const   Text Description;
    const   Vec3 Color;
    const   Text ClubLink;
    const   Text BroadcastTVLogin;
    const   Text SteamUserId;
    const   Integer FameStars;
    const   EEchelon Echelon;
    const   Boolean IsBeginner;
    const   Integer LadderRank;
    const   Integer LadderTotal;
    const   Real LadderPoints;
    const   Text LadderZoneName;
    const   Text LadderZoneFlagUrl;
    const   Integer RequestedClan;
    const   Boolean RequestsSpectate;
    const   Boolean IsFakeUser;
    const   Integer[] Tags_Favored_Indices;
    const   Text[] Tags_Id;
    const   ETagType[] Tags_Type;
    const   Text[] Tags_Comments;
    const   Text[] Tags_Deliverer;
    const   Text[] AlliesConnected;
    const   EStereoDisplayMode StereoDisplayMode;
    enum PlayerType {
            Human,
            Fake (not net),
            Net,
            Replay,
    };
    enum SpectatorMode {
            Void,
            Watcher,
            LocalWatcher,
            Target,
    };
};

struct CTitle : public CNod {
    const   Text TitleId;
    const   Text BaseTitleId;
    const   Text Name;
    const   Text Desc;
    const   Text InfoUrl;
    const   Text DownloadUrl;
    const   Text TitleVersion;
};

struct CMlEvent : public CNod {
    enum Type {
            KeyPress,
            MouseClick,
            MouseOver,
            MouseOut,
            EntrySubmit,
            MenuNavigation,
            PluginCustomEvent,
    };
    enum EMenuNavAction {
            Up,
            Right,
            Left,
            Down,
            Select,
            Cancel,
            PageUp,
            PageDown,
    };
    const   Type Type;
    const   Integer KeyCode;
    const   Text KeyName;
    const   Text CharPressed;
    const   Text ControlId;
    const   CMlControl Control;
    const   EMenuNavAction MenuNavAction;
    const   Text CustomEventType;
    const   Text[] CustomEventData;
};

struct CXmlManager : public CNod {
                    CXmlDocument Create(Text Contents);
                    CXmlDocument Create(Text Contents,Boolean GenerateText,Boolean GenerateTextRaw,Boolean GenerateTextResursive);
                    Void Destroy(CXmlDocument Document);
    const   CXmlDocument[] Documents;
};

struct CHttpManager : public CNod {
                    CHttpRequest CreateGet(Text Url);
                    CHttpRequest CreateGet(Text Url,Boolean UseCache);
                    CHttpRequest CreatePost(Text Url,Text Resource);
                    Void Destroy(CHttpRequest Request);
                    Boolean IsValidUrl(Text Url);
    const   CHttpRequest[] Requests;
    const   Integer SlotsAvailable;
};

struct CAudioManager : public CNod {
    enum ELibSound {
            Alert,
            ShowDialog,
            HideDialog,
            ShowMenu,
            HideMenu,
            Focus,
            Valid,
            Start,
            Countdown,
            Victory,
            ScoreIncrease,
            Checkpoint,
    };
                    CAudioSound CreateSound(Text Url);
                    CAudioSound CreateSound(Text Url,Real VolumedB,Boolean IsMusic,Boolean IsLooping,Boolean IsSpatialized);
                    Void DestroySound(CAudioSound Sound);
    const   CAudioSound[] Sounds;
                    Void PlaySoundEvent(CAudioSound Sound,Real VolumedB);
                    Void PlaySoundEvent(Text Url,Real VolumedB);
                    Void PlaySoundEvent(ELibSound Sound,Integer SoundVariant,Real VolumedB);
                    Void PlaySoundEvent(CAudioSound Sound,Real VolumedB,Integer Delay);
                    Void PlaySoundEvent(Text Url,Real VolumedB,Integer Delay);
                    Void PlaySoundEvent(ELibSound Sound,Integer SoundVariant,Real VolumedB,Integer Delay);
                    Void ClearAllDelayedSoundsEvents();
                    Boolean ForceEnableMusic;
                    Real LimitMusicVolumedB;
};

struct CMlControl : public CNod {
    enum AlignHorizontal {
            Left,
            HCenter,
            Right,
            None,
    };
    enum AlignVertical {
            Top,
            VCenter,
            Bottom,
            None,
            VCenter2,
    };
    const   Text ControlId;
    const   Text[] ControlClasses;
                    Boolean HasClass(Text Class);
                    Vec2 Size;
                    AlignHorizontal HorizontalAlign;
                    AlignVertical VerticalAlign;
                    Boolean Visible;
                    Vec3 RelativePosition;
                    Real RelativeScale;
                    Real RelativeRotation;
    const   Vec3 AbsolutePosition;
    const   Real AbsoluteScale;
    const   Real AbsoluteRotation;
                    Boolean DataAttributeExists(Text DataName);
                    Text DataAttributeGet(Text DataName);
                    Void DataAttributeSet(Text DataName,Text DataValue);
                    Void Show();
                    Void Hide();
                    Void Unload();
                    Void Focus();
};

struct CMlGraphCurve : public CNod {
                    Vec2[] Points;
                    Vec3 Color;
                    Void SortPoints();
                    Text Style;
                    Real Width;
};

struct CMap : public CNod {
    const   CMapInfo MapInfo;
                    Text MapName;
                    Text Comments;
    const   Text AuthorZoneIconUrl;
    const   Text CollectionName;
    const   Text DecorationName;
    const   Text AuthorLogin;
    const   Text AuthorNickName;
    const   Text AuthorZonePath;
    const   Text MapType;
    const   Text MapStyle;
                    Integer TMObjective_AuthorTime;
                    Integer TMObjective_GoldTime;
                    Integer TMObjective_SilverTime;
                    Integer TMObjective_BronzeTime;
                    Integer TMObjective_NbLaps;
                    Boolean TMObjective_IsLapRace;
                    Text ObjectiveTextAuthor;
                    Text ObjectiveTextGold;
                    Text ObjectiveTextSilver;
                    Text ObjectiveTextBronze;
    const   Integer CopperPrice;
    const   Int3 Size;
};

struct CUILayer : public CNod {
    enum EUILayerType {
            Normal,
            ScoresTable,
            ScreenIn3d,
            AltMenu,
            Markers,
            CutScene,
            InGameMenu,
            EditorPlugin,
            ManiaplanetPlugin,
            ManiaplanetMenu,
            LoadingScreen,
    };
                    Boolean IsVisible;
                    EUILayerType Type;
                    Text AttachId;
                    Text ManialinkPage;
    const   CMlPage LocalPage;
};

struct CEditorPluginEvent : public CManiaAppEvent {
    enum Type {
            LayerCustomEvent,
            KeyPress,
            (reserved),
            MenuNavigation,
            CursorSelectionBegin,
            CursorSelectionEnd,
            CursorChange,
            MapModified,
            EditorInput,
            EditAnchor,
            EditObjectives,
            StartValidation,
    };
    enum EInput {
            Unknown,
            Menu,
            SwitchToRace,
            CursorUp,
            CursorRight,
            CursorDown,
            CursorLeft,
            CursorRaise,
            CursorLower,
            CursorTurn,
            CursorPick,
            CursorPlace,
            CursorDelete,
            CameraUp,
            CameraRight,
            CameraDown,
            CameraLeft,
            IconUp,
            IconRight,
            IconDown,
            IconLeft,
    };
    const   Type Type;
    const   EInput Input;
    const   Ident EditedAnchorDataId;
};

struct CBlockModel : public CCollector {
    enum EBaseType {
            None,
            Conductor,
            Generator,
            Collector,
    };
    enum EWayPointType {
            Start,
            Finish,
            Checkpoint,
            None,
            StartFinish,
    };
    enum EProdState {
            Obsolete,
            GameBox,
            DevBuild,
            Release,
    };
    const   Text Name;
    const   Boolean IsRoad;
    const   Boolean IsTerrain;
    const   EWayPointType WaypointType;
    const   Boolean NoRespawn;
    const   CBlockModelVariantGround VariantGround;
    const   CBlockModelVariantAir VariantAir;
};

struct CMacroblockModel : public CCollector {
    const   Boolean IsGround;
    const   Boolean HasStart;
    const   Boolean HasFinish;
    const   Boolean HasCheckpoint;
    const   CBlockModel GeneratedBlockModel;
    const   Text Name;
};

struct CItemAnchor : public CNod {
    enum CardinalDirections {
            North,
            East,
            South,
            West,
    };
    const   Vec3 Position;
};

struct CBlock : public CNod {
    enum CardinalDirections {
            North,
            East,
            South,
            West,
    };
    const   Integer BlockScriptId;
    const   Boolean CanHaveAnchor;
                    Void UseDefaultAnchor();
                    Void UseCustomAnchor();
    const   Int3 Coord;
    const   CardinalDirections Direction;
    const   CBlockUnit[] BlockUnits;
    const   CBlockModel BlockModel;
};

struct CAnchorData : public CNod {
    const   Text DefaultTag;
    const   Integer DefaultOrder;
                    Text Tag;
                    Integer Order;
};

struct CMode : public CNod {
    enum EMedal {
            None,
            Finished,
            Bronze,
            Silver,
            Gold,
            Author,
    };
                    Text ModeStatusMessage;
    const   CTitle LoadedTitle;
    const   Text ServerLogin;
    const   Text ServerName;
    const   Text ServerModeName;
    const   Text MapName;
    const   CMap Map;
    const   Text MapPlayerModelName;
    const   CUser[] Users;
    const   CTeam[] Teams;
                    Text NeutralEmblemUrl;
    const   Text ForcedClubLinkUrl1;
    const   Text ForcedClubLinkUrl2;
                    Void TweakTeamColorsToAvoidHueOverlap();
    const   Integer Now;
    const   Integer Period;
                    Boolean MatchEndRequested;
    const   Boolean ServerShutdownRequested;
    const   Boolean MapLoaded;
                    Void RequestLoadMap();
                    Void RequestUnloadMap();
    const   CMapInfo[] MapList;
                    Integer NextMapIndex;
    const   CUIConfigMgr UIManager;
                    Void Ladder_OpenMatch_Request();
                    Void Ladder_AddPlayer(CScore PlayerScore);
                    Void Ladder_OpenMatch_BeginRequest();
                    Void Ladder_OpenMatch_AddPlayer(CScore PlayerScore);
                    Void Ladder_OpenMatch_EndRequest();
                    Void Ladder_CloseMatchRequest();
                    Void Ladder_CancelMatchRequest();
    const   Boolean Ladder_RequestInProgress;
                    Void Ladder_SetResultsVersion(Integer Version);
                    Void Ladder_SetMatchMakingMatchId(Integer MatchId);
                    Void Ladder_EnableChallengeMode(Boolean Enable);
                    Boolean Admin_KickUser(CUser User,Text Reason);
                    Void Admin_SetLobbyInfo(Boolean IsLobby,Integer LobbyPlayerCount,Integer LobbyMaxPlayerCount,Real LobbyPlayersLevel);
                    Void AutoTeamBalance();
                    Void Solo_SetNewRecord(CScore PlayerScore,EMedal PlayerScore);
    const   Boolean Solo_NewRecordSequenceInProgress;
    const   CXmlRpc XmlRpc;
    const   CXmlManager Xml;
    const   CHttpManager Http;
                    Integer Synchro_AddBarrier();
                    Boolean Synchro_BarrierReached(Integer Barrier);
                    Boolean Users_AreAllies(CUser User1,CUser User2);
                    Void Users_RequestSwitchToSpectator(CUser User);
                    CUser Users_CreateFake(Text NickName,Integer RequestedTeam);
                    Void Users_DestroyFake(CUser User);
                    Void Users_SetNbFakeUsers(Integer NbTeam1,Integer NbTeam2);
                    Void Users_DestroyAllFakes();
                    Void ItemList_Begin();
                    Ident ItemList_Add(Text ModelName);
                    Ident ItemList_AddWithSkin(Text ModelName,Text SkinName);
                    Void ItemList_End();
                    Void DemoToken_StartUsingToken();
                    Void DemoToken_StopUsingToken();
                    Void DemoToken_GetAndUseToken(CUser User);
                    Void ActionList_Begin();
                    Ident ActionList_Add(Text ActionName);
                    Void ActionList_End();
                    Boolean UseMinimap;
                    Boolean Replay_AutoStart;
                    Void Replay_Start();
                    Void Replay_Stop();
};

struct CSmPlayer : public CPlayer {
    enum ESpawnStatus {
            NotSpawned,
            Spawning,
            Spawned,
    };
    const   CSmScore Score;
    const   ESpawnStatus SpawnStatus;
    const   Integer StartTime;
                    Integer EndTime;
                    Real AmmoGain;
                    Real AmmoPower;
    const   Boolean AutoSwitchWeapon;
    const   Integer CurWeapon;
    const   Integer CurAmmo;
    const   Integer CurAmmoMax;
    const   Integer CurAmmoUnit;
                    Integer Armor;
                    Integer ArmorMax;
                    Integer ArmorGain;
                    Integer ArmorReplenishGain;
                    Real ArmorPower;
                    Integer Stamina;
                    Real StaminaMax;
                    Real StaminaGain;
                    Real StaminaPower;
                    Real SpeedPower;
                    Real JumpPower;
                    Boolean AllowWallJump;
                    Boolean AllowProgressiveJump;
                    Boolean UseAlternateWeaponVisual;
                    Boolean IsHighlighted;
                    Real EnergyLevel;
                    Vec3 ForceColor;
                    Ident ForceModelId;
                    Boolean HasShield;
                    Real ThrowSpeed;
    const   Integer CurrentClan;
    const   Integer IdleDuration;
    const   Vec3 Position;
    const   Real AimYaw;
    const   Real AimPitch;
    const   Vec3 AimDirection;
    const   Boolean IsUnderground;
    const   Boolean IsTouchingGround;
    const   Boolean IsInAir;
    const   Boolean IsOnTechGround;
    const   Boolean IsOnTechLaser;
    const   Boolean IsOnTechArrow;
    const   Boolean IsOnTechArmor;
    const   Boolean IsOnTechSafeZone;
    const   Boolean IsOnTech;
    const   Boolean IsOnTechNoWeapon;
    const   Boolean IsInWater;
    const   Vec3 Velocity;
    const   Real Speed;
    const   Boolean IsInOffZone;
    const   Boolean IsCapturing;
    const   CSmMapLandmark CapturedLandmark;
    const   CSmObject[] Objects;
    const   Boolean IsFakePlayer;
    const   Boolean IsBot;
    const   CSmPlayerDriver Driver;
};

struct CSmModeEvent : public CNod {
    enum EType {
            Unknown,
            OnShoot,
            OnHit,
            OnNearMiss,
            OnArmorEmpty,
            OnCapture,
            OnShotDeny,
            OnFallDamage,
            OnCommand,
            OnPlayerAdded,
            OnPlayerRemoved,
            OnPlayerRequestRespawn,
            OnActionCustomEvent,
            OnActionEvent,
            OnPlayerTouchesObject,
            OnPlayerThrowsObject,
            OnPlayerRequestActionChange,
    };
    enum EActionSlot {
            Slot_A,
            Slot_B,
            Slot_C,
            Slot_D,
            Slot_E,
            Slot_F,
            Slot_G,
            Slot_H,
    };
    enum EActionInput {
            Weapon,
            Movement,
            Activable1,
            Activable2,
            Activable3,
            Activable4,
            Consumable1,
            Consumable2,
            None,
    };
    enum EActionSlots {
            Weapon,
            Movement,
            Activable1,
            Activable2,
            Activable3,
            Activable4,
            None,
    };
    const   EType Type;
    const   CSmPlayer Player;
                    Integer Damage;
    const   CSmObject VictimObject;
                    Integer ShooterPoints;
    const   CSmPlayer Shooter;
    const   CSmPlayer Victim;
    const   Real Height;
    const   Real MissDist;
    const   Integer WeaponNum;
    const   Boolean ShooterUsedAction;
    const   Integer ShooterWeaponNum;
    const   EActionSlot ShooterActionSlot;
    const   Text ShooterActionId;
    const   Boolean VictimUsedAction;
    const   Integer VictimWeaponNum;
    const   EActionSlot VictimActionSlot;
    const   Text VictimActionId;
    const   EActionSlot Action_Slot;
    const   EActionInput ActionInput;
    const   Text ActionId;
    const   Text Param1;
    const   Text[] Param2;
    const   CSmObject Object;
    const   CSmBlockPole BlockPole;
    const   CSmMapLandmark Landmark;
    const   Ident PlayerId;
    const   CUser User;
    const   Boolean PlayerWasSpawned;
    const   Boolean PlayerWasInLadderMatch;
    const   Vec3 PlayerLastPosition;
    const   Vec3 PlayerLastAimDirection;
    const   Boolean GiveUp;
    const   Text CommandName;
    const   Boolean CommandValueBoolean;
    const   Integer CommandValueInteger;
    const   Real CommandValueReal;
    const   Text CommandValueText;
    const   Integer ActionChange;
};

struct CSmMapBase : public CNod {
                    Integer Clan;
                    Boolean IsActive;
    const   Integer NumberOfCollectors;
};

struct CSmMapLandmark : public CNod {
    const   Text Tag;
    const   Integer Order;
    const   Vec3 Position;
    const   CSmMapBase Base;
    const   CSmMapGate Gate;
    const   CSmMapGauge Gauge;
    const   CSmMapSector Sector;
    const   CSmMapPlayerSpawn PlayerSpawn;
    const   CSmMapBotPath BotPath;
    const   CSmMapObjectAnchor ObjectAnchor;
};

struct CSmScore : public CScore {
    const   Integer TeamNum;
                    Integer Points;
                    Integer RoundPoints;
    const   Integer NbEliminationsInflicted;
    const   Integer NbEliminationsTaken;
    const   Integer NbRespawnsRequested;
    const   Integer DamageInflicted;
    const   Integer DamageTaken;
                    Void Clear();
};

struct CSmObject : public CNod {
    enum EStatus {
            OnPlayer,
            OnAnchor,
            InWorld,
            Unspawned,
    };
    const   EStatus Status;
    const   Ident ModelId;
                    Void SetAnchor(CSmMapObjectAnchor ObjectAnchor);
                    Void SetPlayer(CSmPlayer Player);
                    Void SetPosition(Vec3 Position);
                    Void SetPositionAndVel(Vec3 Position,Vec3 Vel);
                    Void SetUnspawned();
    const   CSmPlayer Player;
    const   Vec3 Position;
    const   Vec3 Vel;
                    Integer MachineState;
                    Boolean Throwable;
};

struct CMlScriptIngame : public CMlScript {
    enum EUISound {
            Default,
            Silence,
            StartMatch,
            EndMatch,
            StartRound,
            EndRound,
            PhaseChange,
            TieBreakPoint,
            TiePoint,
            VictoryPoint,
            Capture,
            TimeOut,
            Notice,
            Warning,
            PlayerEliminated,
            PlayerHit,
            Checkpoint,
            Finish,
            Record,
            ScoreProgress,
            RankChange,
            Bonus,
            FirstHit,
            Combo,
            PlayersRemaining,
            Custom1,
            Custom2,
            Custom3,
            Custom4,
    };
    enum EInGameMenuResult {
            Resume,
            Quit,
            NormalMenu,
            AdvancedMenu,
            ServerSettings,
    };
    const   Integer GameTime;
                    CUIConfig UI;
                    CUIConfig ClientUI;
                    Boolean IsSpectatorMode;
    const   Boolean UseClans;
    const   Boolean UseForcedClans;
    const   CMap Map;
                    Void ShowCurChallengeCard();
                    Void ShowModeHelp();
                    Void CopyServerLinkToClipBoard();
                    Void JoinTeam1();
                    Void JoinTeam2();
    const   CTeam[] Teams;
                    Void SetSpectateTarget(Text Player);
                    Void ShowProfile(Text Player);
                    Void ShowInGameMenu();
    const   Text CurrentServerLogin;
    const   Text CurrentServerName;
    const   Text CurrentServerJoinLink;
    const   Text CurrentServerModeName;
                    Void PlayUiSound(EUISound Sound,Integer SoundVariant,Real Volume);
                    Void CloseInGameMenu(EInGameMenuResult Result);
};

struct CSmActionEvent : public CNod {
    enum EType {
            OnHitPlayer,
            OnProjectileStart,
            OnProjectileEnd,
            OnActiveChange,
    };
    const   EType Type;
    const   CSmPlayer Player;
    const   Integer Damage;
    const   Ident ProjectileModelId;
    const   Integer ContextId;
    const   Vec3 Position;
    const   Vec3 Direction;
    const   Vec3 Normal;
};

struct CMapType : public CEditorPlugin {
    enum ValidationStatus {
            NotValidable,
            Validable,
            Validated,
    };
                    Boolean CustomEditAnchorData;
                    Void ClearMapMetadata();
                    ValidationStatus ValidationStatus;
                    Text ValidabilityRequirementsMessage;
    const   Boolean ValidationEndRequested;
                    Void StartTestMapWithMode(Text RulesModeName);
                    Void RequestEnterPlayground();
                    Void RequestLeavePlayground();
    const   Boolean IsSwitchedToPlayground;
};

struct CTmMlPlayer : public CPlayer {
    enum ERaceState {
            BeforeStart,
            Running,
            Finished,
            Eliminated,
    };
    const   Integer CurrentClan;
    const   ERaceState RaceState;
    const   Boolean IsSpawned;
                    CTrackManiaScore Score;
    const   Integer RaceStartTime;
    const   Integer LapStartTime;
                    CTmResult CurRace;
                    CTmResult CurLap;
    const   Integer CurrentNbLaps;
    const   Integer CurTriggerIndex;
    const   Integer CurCheckpointRaceTime;
    const   Integer CurCheckpointLapTime;
    const   Real AccelCoef;
    const   Real ControlCoef;
    const   Vec3 Position;
    const   Real AimYaw;
    const   Real AimPitch;
    const   Vec3 AimDirection;
    const   Real Distance;
    const   Real Speed;
    const   Integer DisplaySpeed;
};

struct CTmScore : public CScore {
    const   Integer TeamNum;
                    Integer Points;
                    CTmResult BestRace;
                    CTmResult BestLap;
                    Integer PrevRaceDeltaPoints;
                    CTmResult PrevRace;
                    CTmResult TempResult;
                    Void Clear();
};

struct CTmPlayer : public CPlayer {
    const   Integer CurrentClan;
    const   CTmScore Score;
                    Integer RaceStartTime;
                    Boolean IsSpawned;
                    CTmResult CurRace;
                    CTmResult CurLap;
                    Integer CurrentNbLaps;
    const   Integer CurTriggerIndex;
    const   Vec3 Position;
    const   Real AimYaw;
    const   Real AimPitch;
    const   Vec3 AimDirection;
                    Real AccelCoef;
                    Real ControlCoef;
};

struct CTmModeEvent : public CNod {
    enum EType {
            Unknown,
            StartLine,
            WayPoint,
            GiveUp,
            Respawn,
            Stunt,
            OnPlayerAdded,
            OnPlayerRemoved,
    };
    enum EStuntFigure {
            None,
            StraightJump,
            Flip,
            BackFlip,
            Spin,
            Aerial,
            AlleyOop,
            Roll,
            Corkscrew,
            SpinOff,
            Rodeo,
            FlipFlap,
            Twister,
            FreeStyle,
            SpinningMix,
            FlippingChaos,
            RollingMadness,
            WreckNone,
            WreckStraightJump,
            WreckFlip,
            WreckBackFlip,
            WreckSpin,
            WreckAerial,
            WreckAlleyOop,
            WreckRoll,
            WreckCorkscrew,
            WreckSpinOff,
            WreckRodeo,
            WreckFlipFlap,
            WreckTwister,
            WreckFreeStyle,
            WreckSpinningMix,
            WreckFlippingChaos,
            WreckRollingMadness,
            TimePenalty,
            RespawnPenalty,
            Grind,
            Reset,
    };
    const   EType Type;
    const   CTmPlayer Player;
                    Integer RaceTime;
    const   Integer CheckpointInRace;
    const   Integer CheckpointInLap;
    const   Boolean IsEndLap;
    const   Boolean IsEndRace;
                    Integer LapTime;
                    Integer StuntsScore;
                    Integer NbRespawns;
    const   Ident BlockId;
                    Real Speed;
                    Real Distance;
                    Real Damages;
    const   EStuntFigure StuntFigure;
    const   Integer Angle;
    const   Integer Points;
    const   Integer Combo;
    const   Boolean IsStraight;
    const   Boolean IsReverse;
    const   Boolean IsMasterJump;
    const   Real Factor;
    const   CUser User;
    const   Boolean PlayerWasSpawned;
    const   Boolean PlayerWasInLadderMatch;
};

struct CMlFrame : public CMlControl {
    enum EControlType {
            Audio,
            Entry,
            FileEntry,
            Frame,
            Label,
            Quad,
            Video,
    };
    const   CMlControl[] Controls;
                    CMlControl GetFirstChild(Text ControlId);
                    Boolean ClipWindowActive;
                    Vec2 ClipWindowRelativePosition;
                    Vec2 ClipWindowSize;
};

struct CXmlDocument : public CNod {
    const   Text TextContents;
    const   CXmlNode Root;
    const   CXmlNode[] Nodes;
                    CXmlNode GetFirstChild(Text Name);
};

struct CHttpRequest : public CNod {
    const   Text Url;
    const   Text Result;
    const   Integer StatusCode;
    const   Boolean IsCompleted;
};

struct CAudioSound : public CNod {
                    Void Play();
                    Void Stop();
    const   Boolean IsPlaying;
    const   Boolean DownloadInProgress;
                    Real Volume;
                    Real VolumedB;
                    Real Pitch;
                    Vec3 RelativePosition;
                    Real PlayCursor;
    const   Real PlayLength;
};

struct CMapInfo : public CNod {
    const   Text Comments;
    const   Integer CopperPrice;
    const   Text CollectionName;
    const   Text AuthorLogin;
    const   Text AuthorNickName;
    const   Text AuthorZonePath;
    const   Text MapType;
    const   Text MapStyle;
    const   Boolean Unlocked;
    const   Text Name;
    const   Text Path;
};

struct CCollector : public CNod {
    const   Text Name;
                    Text PageName;
};

struct CBlockModelVariantGround : public CBlockModelVariant {
    enum EnumAutoTerrainPlaceType {
            Auto,
            Force,
            DoNotPlace,
            DoNotDestroy,
    };
};

struct CBlockModelVariantAir : public CBlockModelVariant {
};

struct CBlockUnit : public CNod {
    const   Int3 Offset;
    const   CBlockUnitModel BlockUnitModel;
    const   CBlock Block;
};

struct CTeam : public CNod {
                    Text Name;
                    Text ZonePath;
                    Text City;
                    Text EmblemUrl;
                    Text PresentationManialinkUrl;
                    Text ClubLinkUrl;
                    Vec3 ColorPrimary;
                    Vec3 ColorSecondary;
    const   Text ColorText;
    const   Text ColorizedName;
};

struct CUIConfigMgr : public CNod {
                    Void ResetAll();
    const   CUIConfig UIAll;
    const   CUIConfig[] UI;
                    CUIConfig GetUI(CPlayer Player);
                    CUIConfig GetUI(CUser User);
    const   CUILayer[] UILayers;
                    CUILayer UILayerCreate();
                    Void UILayerDestroy(CUILayer Layer);
                    Void UILayerDestroyAll();
    const   CUILayer[] UIReplayLayers;
                    Integer UISequenceMaxDuration;
};

struct CXmlRpc : public CNod {
    const   CXmlRpcEvent[] PendingEvents;
                    Void SendCallback(Text Param1,Text Param2);
                    Void SendCallbackArray(Text Type,Text[] Data);
                    Void SendCallback_BeginRound();
                    Void SendCallback_EndRound();
};

struct CPlayer : public CNod {
    const   CUser User;
    const   Text Login;
    const   Text Name;
    const   Integer RequestedClan;
    const   Boolean RequestsSpectate;
};

struct CSmPlayerDriver : public CNod {
    enum ESmDriverBehaviour {
            Static,
            Turret,
            Scripted,
            IA,
            Patrol,
            Escape,
            Saunter,
    };
    enum ESmDriverPatrolMode {
            OneTrip,
            BackAndForth,
            Loop,
    };
    enum ESmAttackFilter {
            All,
            AllPlayers,
            AllBots,
            AllOpposite,
            OppositePlayers,
            OppositeBots,
            Nobody,
    };
                    ESmDriverBehaviour Behaviour;
                    Real AggroRadius;
                    Real DisengageDistance;
                    Real PathSpeedCoef;
                    Real Accuracy;
                    Integer ReactionTime;
                    Integer ShootPeriodMin;
                    Integer ShootPeriodMax;
                    Boolean RocketAnticipation;
                    Real Fov;
                    ESmAttackFilter AttackFilter;
    const   CSmPlayer Target;
    const   Boolean IsStuck;
                    Boolean IsFlying;
                    Integer PathOffset;
                    Real Agressivity;
                    Boolean UseOldShootingSystem;
                    ESmDriverPatrolMode Patrol_Mode;
                    Vec3 Escape_AnchorPoint;
                    Real Escape_DistanceSafe;
                    Real Escape_DistanceMinEscape;
                    Real Escape_DistanceMaxEscape;
                    Vec3 Saunter_AnchorPoint;
                    Integer Saunter_BaseChillingTime;
                    Integer Saunter_ChillingTimeDelta;
                    Real Saunter_Radius;
                    Boolean Scripted_ForceAimInMoveDir;
                    CSmPlayer ForcedTarget;
                    CSmPlayer[] TargetsToAvoid;
};

struct CSmBlockPole : public CSmBlock {
                    Boolean Captured;
    const   CSmSector Sector;
    const   CSmGauge Gauge;
};

struct CSmMapGate : public CNod {
                    Integer Clan;
                    Boolean Automatic;
                    Boolean ManualClosed;
    const   Boolean AutoClosed;
                    Boolean AutoIsActive;
                    Integer AutoCloseDelay;
                    Integer AutoOpenSpeed;
};

struct CSmMapGauge : public CNod {
                    Integer Clan;
                    Real ValueReal;
                    Integer Value;
                    Integer Max;
                    Integer Speed;
                    Boolean Captured;
};

struct CSmMapSector : public CNod {
    const   Ident[] PlayersIds;
};

struct CSmMapPlayerSpawn : public CNod {
};

struct CSmMapBotPath : public CNod {
    const   Integer Clan;
    const   Vec3[] Path;
    const   Boolean IsFlying;
};

struct CSmMapObjectAnchor : public CNod {
    const   Text ItemName;
    const   Ident ItemModelId;
};

struct CScore : public CNod {
    const   CUser User;
    const   Boolean IsRegisteredForLadderMatch;
    const   Real LadderScore;
                    Integer LadderRankSortValue;
                    Real LadderMatchScoreValue;
                    Integer LadderClan;
};

struct CUIConfig : public CNod {
    enum EUISequence {
            None,
            Playing,
            Intro,
            Outro,
            Podium,
            CustomMTClip,
            EndRound,
            PlayersPresentation,
            UIInteraction,
            RollingBackgroundIntro,
            CustomMTClip_WithUIInteraction,
    };
    enum EUIStatus {
            None,
            Normal,
            Warning,
            Error,
            Official,
    };
    enum EVisibility {
            None,
            Normal,
            Manual,
            ForcedHidden,
            ForcedVisible,
    };
    enum ELabelsVisibility {
            None,
            Never,
            Always,
            WhenInFrustum,
            WhenVisible,
            WhenInMiddleOfScreen,
    };
    enum EAvatarVariant {
            Default,
            Sad,
            Happy,
    };
    enum EUISound {
            Default,
            Silence,
            StartMatch,
            EndMatch,
            StartRound,
            EndRound,
            PhaseChange,
            TieBreakPoint,
            TiePoint,
            VictoryPoint,
            Capture,
            TimeOut,
            Notice,
            Warning,
            PlayerEliminated,
            PlayerHit,
            Checkpoint,
            Finish,
            Record,
            ScoreProgress,
            RankChange,
            Bonus,
            FirstHit,
            Combo,
            PlayersRemaining,
            Custom1,
            Custom2,
            Custom3,
            Custom4,
    };
    enum ENoticeLevel {
            Default,
            PlayerInfo,
            PlayerWarning,
            MapInfo,
            MapWarning,
            MatchInfo,
            MatchWarning,
    };
    enum EObserverMode {
            Default,
            Forced,
            Forbidden,
            Manual,
    };
                    EUISequence UISequence;
    const   Boolean UISequenceIsCompleted;
                    Text UISequence_CustomMTClip;
                    Integer UISequence_CustomMTRefTime;
                    Boolean UISequence_CanSkipIntroMT;
                    Text UISequence_PodiumPlayersWin;
                    Text UISequence_PodiumPlayersLose;
                    Text ManialinkPage;
                    Text BigMessage;
                    Text BigMessageAvatarLogin;
                    EAvatarVariant BigMessageAvatarVariant;
                    EUISound BigMessageSound;
                    Integer BigMessageSoundVariant;
                    Text StatusMessage;
                    Text GaugeMessage;
                    Real GaugeRatio;
                    Integer GaugeClan;
                    Text MarkersXML;
    const   CUILayer[] UILayers;
                    Boolean OverlayHideNotices;
                    Boolean OverlayHideMapInfo;
                    Boolean OverlayHideOpponentsInfo;
                    Boolean OverlayHideChat;
                    Boolean OverlayHideCheckPointList;
                    Boolean OverlayHideRoundScores;
                    Boolean OverlayHideCountdown;
                    Boolean OverlayHideCrosshair;
                    Boolean OverlayHideGauges;
                    Boolean OverlayHideConsumables;
                    Boolean OverlayHide321Go;
                    Boolean OverlayHideBackground;
                    Boolean OverlayHideChrono;
                    Boolean OverlayHideSpeedAndDist;
                    Boolean OverlayHidePersonnalBestAndRank;
                    Boolean OverlayHidePosition;
                    Boolean OverlayHideCheckPointTime;
                    Boolean OverlayHideEndMapLadderRecap;
                    Boolean OverlayHideMultilapInfos;
                    Boolean OverlayHideSpectatorControllers;
                    Boolean OverlayHideSpectatorInfos;
                    Boolean OverlayChatHideAvatar;
                    Integer OverlayChatLineCount;
                    Vec2 OverlayChatOffset;
                    Vec2 CountdownCoord;
                    Boolean NoticesFilter_HidePlayerInfo;
                    Boolean NoticesFilter_HidePlayerWarning;
                    Boolean NoticesFilter_HidePlayerInfoIfNotMe;
                    Boolean NoticesFilter_HidePlayerWarningIfNotMe;
                    Boolean NoticesFilter_HideMapInfo;
                    Boolean NoticesFilter_HideMapWarning;
                    Boolean NoticesFilter_HideMatchInfo;
                    Boolean NoticesFilter_HideMatchWarning;
                    ENoticeLevel NoticesFilter_LevelToShowAsBigMessage;
                    Text ScoreTable;
                    EVisibility ScoreTableVisibility;
                    Text SmallScoreTable;
                    EVisibility SmallScoreTableVisibility;
                    Boolean ScoreTableOnlyManialink;
                    Boolean AltMenuNoDefaultScores;
                    Boolean AltMenuNoCustomScores;
                    Boolean OverlayScoreSummary;
                    Ident ScoreSummary_Player1;
                    Integer ScoreSummary_Points1;
                    Integer ScoreSummary_RoundPoints1;
                    Integer ScoreSummary_MatchPoints1;
                    Real ScoreSummary_Gauge1;
                    Ident ScoreSummary_Player2;
                    Integer ScoreSummary_Points2;
                    Integer ScoreSummary_RoundPoints2;
                    Integer ScoreSummary_MatchPoints2;
                    Real ScoreSummary_Gauge2;
                    Boolean ScreenIn3dHideScoreSummary;
                    Boolean ScreenIn3dHideVersus;
                    Integer CountdownEndTime;
                    EUIStatus UIStatus;
                    ELabelsVisibility AlliesLabelsVisibility;
                    EVisibility AlliesLabelsShowGauges;
                    EVisibility AlliesLabelsShowNames;
                    Integer AlliesLabelsMaxCount;
                    ELabelsVisibility TeamLabelsVisibility;
                    EVisibility TeamLabelsShowGauges;
                    EVisibility TeamLabelsShowNames;
                    ELabelsVisibility OpposingTeamLabelsVisibility;
                    EVisibility OpposingTeamLabelsShowGauges;
                    EVisibility OpposingTeamLabelsShowNames;
                    Boolean ForceSpectator;
                    Integer SpectatorForceCameraType;
                    Ident SpectatorAutoTarget;
                    Ident SpectatorForcedTarget;
                    Integer SpectatorForcedClan;
                    Real SpectatorCamAutoLatitude;
                    Real SpectatorCamAutoLongitude;
                    Real SpectatorCamAutoRadius;
                    EObserverMode SpectatorObserverMode;
                    Void SendChat(Text Text);
                    Void SendNotice(Text Text,ENoticeLevel Level,CUser Avatar,EAvatarVariant AvatarVariant,EUISound Sound,Integer SoundVariant);
                    Text GetLayerManialinkAction(CUILayer Layer);
                    Void ClearLayerManialinkAction(CUILayer Layer);
};

struct CTrackManiaScore : public CTmScore {
};

struct CTmResult : public CNod {
    enum ETmRaceResultCriteria {
            Time,
            Stunts,
            NbRespawns,
            CheckpointsProgress,
            None,
    };
                    Integer Time;
                    Integer StuntsScore;
                    Integer NbRespawns;
                    Integer[] Checkpoints;
                    Integer Compare(CTmResult Other,ETmRaceResultCriteria Criteria);
};

struct CXmlNode : public CNod {
    const   Text Name;
    const   Text TextContents;
    const   Text TextRawContents;
    const   Text TextRecursiveContents;
    const   CXmlNode[] Children;
                    Text GetAttributeText(Text Name,Text DefaultValue);
                    Integer GetAttributeInteger(Text Name,Integer DefaultValue);
                    Real GetAttributeReal(Text Name,Real DefaultValue);
                    Boolean GetAttributeBoolean(Text Name,Boolean DefaultValue);
                    CXmlNode GetFirstChild(Text Name);
};

struct CBlockModelVariant : public CNod {
                    Text Name;
    const   Boolean IsAllUnderground;
    const   Boolean IsPartUnderground;
    const   Int3 Size;
    const   Int3 OffsetBoundingBoxMin;
    const   Int3 OffsetBoundingBoxMax;
                    CBlockUnitModel[] BlockUnitModels;
};

struct CBlockUnitModel : public CNod {
    enum CardinalDirEnum {
            North,
            East,
            South,
            West,
    };
    enum MultiDirEnum {
            SameDir,
            SymmetricalDirs,
            AllDir,
            OpposedDirOnly,
            PerpendicularDirsOnly,
            NextDirOnly,
            PreviousDirOnly,
    };
    const   Int3 Offset;
    const   CBlockModelClip[] Clips;
};

struct CXmlRpcEvent : public CNod {
    enum EType {
            Unknown,
            Callback,
            CallbackArray,
    };
    const   EType Type;
    const   Text Param1;
    const   Text Param2;
    const   Text ParamArray1;
    const   Text[] ParamArray2;
};

struct CSmBlock : public CSmLandmark {
    const   CSmBase Base;
};

struct CSmSector : public CNod {
    const   Ident[] PlayersIds;
};

struct CSmGauge : public CNod {
                    Integer Clan;
                    Real ValueReal;
                    Integer Value;
                    Integer Max;
                    Integer Speed;
};

struct CBlockModelClip : public CBlockModel {
    enum EnumClipType {
            ClassicClip,
            FreeClipSide,
            FreeClipTop,
            FreeClipBottom,
    };
    enum MultiDirEnum {
            SameDir,
            SymmetricalDirs,
            AllDir,
            OpposedDirOnly,
            PerpendicularDirsOnly,
            NextDirOnly,
            PreviousDirOnly,
    };
};

struct CSmLandmark : public CNod {
    const   Text Tag;
    const   Integer Order;
    const   Vec3 Position;
    const   Vec3 DirFront;
};

struct CSmBase : public CNod {
                    Integer Clan;
                    Boolean IsActive;
    const   Integer NumberOfCollectors;
};

namespace MathLib {

    Integer Abs(Integer Argument1);
    Real Abs(Real Argument1);
    Real ToReal(Integer Argument1);
    Real Sin(Real Argument1);
    Real Cos(Real Argument1);
    Real Tan(Real Argument1);
    Real Atan2(Real Argument1, Real Argument2);
    Real Exp(Real Argument1);
    Real Rand(Real Argument1, Real Argument2);
    Integer Rand(Integer Argument1, Integer Argument2);
    Real NearestReal(Integer Argument1);
    Integer NearestInteger(Real Argument1);
    Integer FloorInteger(Real Argument1);
    Integer CeilingInteger(Real Argument1);
    Real Distance(Vec3 Argument1, Vec3 Argument2);
    Real DotProduct(Vec3 Argument1, Vec3 Argument2);
    Vec3 CrossProduct(Vec3 Argument1, Vec3 Argument2);
    Real Angle(Vec3 Argument1, Vec3 Argument2);
    Real OrientedAngle(Vec3 Argument1, Vec3 Argument2);
    Real PI();
    Real Asin(Real Argument1);
    Real Acos(Real Argument1);
    Real Pow(Real Argument1, Real Argument2);
    Real Ln(Real Argument1);
    Real Sqrt(Real Argument1);
    Integer Max(Integer _A, Integer _B);
    Integer Min(Integer _A, Integer _B);
    Integer Clamp(Integer _X, Integer _Min, Integer _Max);
    Real Max(Real _A, Real _B);
    Real Min(Real _A, Real _B);
    Real Clamp(Real _X, Real _Min, Real _Max);
};

namespace TextLib {

    Real ToReal(Text _Text);
    Integer ToInteger(Text _Text);
    Vec3 ToColor(Text _Text);
    Text SubString(Text _Text, Integer _Start, Integer _Length);
    Text SubText(Text _Text, Integer _Start, Integer _Length);
    Integer Length(Text _Text);
    Text ToText(Integer _Integer);
    Text ToText(Real _Real);
    Text ToText(Boolean _Boolean);
    Text ToText(Int3 _Int3);
    Text ToText(Vec3 _Vec3);
    Text TimeToText(Integer _Time, Boolean _IncludeCentiSeconds);
    Text TimeToText(Integer _Time);
    Text ColorToText(Vec3 _Color);
    Text FormatInteger(Integer Argument1, Integer Argument2);
    Text FormatReal(Real _Value, Integer _FPartLength, Boolean _HideZeroes, Boolean _HideDot);
    Text ToUpperCase(Text _TextToChange);
    Text ToLowerCase(Text _TextToChange);
    Boolean CompareWithoutFormat(Text _Text1, Text _Text2, Boolean _IsCaseSensitive);
    Boolean Find(Text _TextToFind, Text _TextToSearchIn, Boolean _IsFormatSensitive, Boolean _IsCaseSensitive);
    Text Compose(Text Argument1);
    Text Compose(Text Argument1, Text Argument2);
    Text Compose(Text Argument1, Text Argument2, Text Argument3);
    Text Compose(Text Argument1, Text Argument2, Text Argument3, Text Argument4);
    Text Compose(Text Argument1, Text Argument2, Text Argument3, Text Argument4, Text Argument5);
    Text Compose(Text Argument1, Text Argument2, Text Argument3, Text Argument4, Text Argument5, Text Argument6);
    Text MLEncode(Text Argument1);
    Text URLEncode(Text Argument1);
    Text StripFormatting(Text Argument1);
    Text[Void] Split(Text Argument1, Text Argument2);
    Text Join(Text Argument1, Text[Void] Argument2);
    Text SmartSplit(Text Argument1, Integer Argument2, Integer Argument3, Integer Argument4);
    Text Trim(Text Argument1);
    Text ReplaceChars(Text Argument1, Text Argument2, Text Argument3);
    Text Replace(Text _Text, Text _ToReplace, Text _Replacement);
    Text GetTranslatedText(Text _Text);
};

namespace MapUnits {

    CardinalDirections GetNextDir(CardinalDirections Argument1);
    CardinalDirections GetPreviousDir(CardinalDirections Argument1);
    CardinalDirections GetOpposedDir(CardinalDirections Argument1);
    CardinalDirections AddDirs(CardinalDirections Argument1, CardinalDirections Argument2);
    CardinalDirections SubDirs(CardinalDirections Argument1, CardinalDirections Argument2);
    Int3 GetNeighbourCoord(Int3 Argument1, CardinalDirections Argument2);
    Int3 GetRotatedOffset(Int3 Argument1, CardinalDirections Argument2);
    Int3 GetRotatedOffsetPositive(Int3 Argument1, CardinalDirections Argument2, Int3 Argument3);
};

namespace AnimLib {

    Real SmoothStep(Real _X);
    Real Ease(Text _Function, Real _T, Real _Base, Real _Change, Real _Duration);
    Real EaseLinear(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInQuad(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseOutQuad(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInOutQuad(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInCubic(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseOutCubic(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInOutCubic(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInQuart(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseOutQuart(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInOutQuart(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInQuint(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseOutQuint(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInOutQuint(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInSine(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseOutSine(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInOutSine(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInExp(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseOutExp(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInOutExp(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInCirc(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseOutCirc(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInOutCirc(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInBack(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseOutBack(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInOutBack(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInElastic(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseOutElastic(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInOutElastic(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInElastic2(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseOutElastic2(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInOutElastic2(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInBounce(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseOutBounce(Integer _T, Real _Base, Real _Change, Integer _Duration);
    Real EaseInOutBounce(Integer _T, Real _Base, Real _Change, Integer _Duration);
};