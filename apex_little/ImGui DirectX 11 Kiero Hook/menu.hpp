#include "includes.h"
#include "visuals.hpp"
#include <thread>
#include <chrono>
#include <time.h>
#include "fonts.h"
#include "icon.h"
#include "colors.h"
#include <string>
#include <tchar.h>
#include <tchar.h>
#include <string>
#include <tchar.h>
#include <d3dx11.h>
#pragma comment(lib, "d3dx11.lib")
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_freetype.h"
#include "imgui/imgui_internal.h"
#pragma comment(lib, "freetype.lib")

//op
#include "pathfinder.h"
#include "revenat.h"
#include "seer.h"
#include "maggie.h"
#include "Bangladesh.h"
#include "Bloodhound.h"
#include "Catalyst.h"
#include "Fuse.h"
#include "Gibraltar.h"
#include "newcastle.h"
#include "Wattson.h"
#include "Wraith.h"
#include "ash.h"
#include "Ballistic.h"
#include "Caustic.h"
#include "Crypto.h"
#include "Lifeline.h"
#include "Loba.h"
#include "Mirage.h"
#include "Octane.h"
#include "Valk.h"
#include "Vantage.h"
#include "Rampart.h"
#include "horizon.h"
//op
int menukey = VK_INSERT;
int menustate;

float pa, pb, pc, pd;
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
bool watermark = false;
Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
//MENU SHIT

int m_tab_count = 0;
int m_active_tab = 0;
float m_tab_alpha = 1.f;
float m_tab_add = 0.f;
float m_tab_checkmark = 0.f;
float color[4] = { 0.345f, 0.094f, 0.400f, 1.000f };


ImFont* ubuntu_bold_font = nullptr;
ImFont* ubuntu_medium_font = nullptr;
ImFont* ubuntu_regular_font = nullptr;
ImFont* expand_font = nullptr;

ID3D11ShaderResourceView* aimbot_texture = nullptr;
ID3D11ShaderResourceView* players_texture = nullptr;
ID3D11ShaderResourceView* world_texture = nullptr;
ID3D11ShaderResourceView* skins_texture = nullptr;
ID3D11ShaderResourceView* settings_texture = nullptr;
ID3D11ShaderResourceView* icon_texture = nullptr;

///////////////////////////////////////////////
float fps;
void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;   // fix mouse issue?

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);

	ImFontConfig cfg;

	cfg.FontBuilderFlags = ImGuiFreeTypeBuilderFlags_ForceAutoHint | ImGuiFreeTypeBuilderFlags_Bitmap;
	ubuntu_bold_font = io.Fonts->AddFontFromMemoryTTF(ubuntu_bold, sizeof ubuntu_bold, 16.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	ubuntu_medium_font = io.Fonts->AddFontFromMemoryTTF(ubuntu_medium, sizeof ubuntu_medium, 14.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	ubuntu_regular_font = io.Fonts->AddFontFromMemoryTTF(ubuntu_regular, sizeof ubuntu_regular, 14.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	expand_font = io.Fonts->AddFontFromMemoryTTF(expand_binary, sizeof expand_binary, 10.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
	esp_font = io.Fonts->AddFontFromMemoryTTF(ubuntu_regular, sizeof ubuntu_regular, 12.f);
	
	io.MouseDrawCursor = false;
}
void HelpMarker(const char* desc) {
	ImGui::TextDisabled(("[?]"));
	if (ImGui::IsItemHovered()) {
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();

	}
}

bool drawmenu = true;

bool showMouse = false;
int* a;
bool weaponScreen = false;
bool attachmentsScreen = false;
bool armorScreen = false;
bool otherScreen = false;

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;
void DrawCross(float x, float y, float width, float height, ImColor col) {
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x - width, y), ImVec2(x + width, y), col, 3);
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(y - height, x), ImVec2(y + height, x), col, 3);
}
inline float dax = 0.0f, day = 3.0f;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			std::thread(DoBhop).detach();
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}
	
	if (GetAsyncKeyState(menukey) & 0x1)
	{
		drawmenu = !drawmenu;
	}
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (GetAsyncKeyState(VK_NUMPAD1) & 0x1 || GetAsyncKeyState(0x05) & 0x1)
	{
		showMouse = !showMouse;
	}

	/*if (!showMouse)
		ImGui::SetMouseCursor(ImGuiMouseCursor_None);*/
	
	if (drawmenu)
	{
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
		ImGui::SetNextWindowSize(ImVec2(700, 500));
		ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBringToFrontOnFocus);
		{
			const ImVec2 pos = ImGui::GetWindowPos();
			ImDrawList* draw = ImGui::GetWindowDrawList();
			ImGuiStyle* style = &ImGui::GetStyle();

			{
				style->WindowPadding = ImVec2(0, 0);
				style->WindowBorderSize = 0.f;
				style->ItemSpacing = ImVec2(15, 15);
				style->WindowRounding = 4.f;
				style->ScrollbarSize = 4.f;
				style->Colors[ImGuiCol_WindowBg] = colors::window_background;
			}

			{

				ImVec2 FUCK1 = { pos.x + 700, pos.y + 500 };
				ImVec2 FUCK2 = { pos.x + 0, pos.y + 45 };
				ImVec2 FUCK3 = { pos.x + 700, pos.y + 47 };
				ImVec2 FUCK4 = { pos.x + 15, pos.y + 62 + m_tab_checkmark };
				ImVec2 FUCK5 = { pos.x + 145, pos.y + 98 + m_tab_checkmark };
				ImVec2 FUCK6 = { pos.x + 700, pos.y + 45 };

				m_tab_checkmark = ImLerp(m_tab_checkmark, 51.f * m_tab_count, ImGui::GetIO().DeltaTime * 12.f);
				ImGui::GetBackgroundDrawList()->AddShadowRect(pos, FUCK1, ImGui::GetColorU32(colors::window_shadow), 60.f, ImVec2(0, 0), 0, style->WindowRounding);
				draw->AddRectFilled(FUCK4, FUCK5, ImGui::GetColorU32(colors::tab_checkmark), style->WindowRounding);
				draw->AddRectFilledMultiColor(FUCK2, FUCK3, ImGui::GetColorU32(colors::accent_one), ImGui::GetColorU32(colors::accent_two), ImGui::GetColorU32(colors::accent_two), ImGui::GetColorU32(colors::accent_one));
				ImGui::PushFont(ubuntu_bold_font);
				ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetColorU32(colors::window_label));
				ImGui::RenderTextClipped(pos, FUCK6, "Apex Legends", NULL, NULL, ImVec2(0.5f, 0.5f));
				ImGui::PopStyleColor();
				ImGui::PopFont();
			}

			{

				ImGui::SetCursorPos(ImVec2(15, 62));
				ImGui::BeginGroup();
				{
					if (ImGui::Tab("Player", players_texture, 0 == m_tab_count))
						m_tab_count = 0;
					if (ImGui::Tab("Combat", aimbot_texture, 1 == m_tab_count))
						m_tab_count = 1;
					if (ImGui::Tab("Misc", skins_texture, 2 == m_tab_count))
						m_tab_count = 2;
					if (ImGui::Tab("Loot", settings_texture, 3 == m_tab_count))
						m_tab_count = 3;
				}
				ImGui::EndGroup();
			}

			{
				m_tab_alpha = ImClamp(m_tab_alpha + (6.f * ImGui::GetIO().DeltaTime * (m_tab_count == m_active_tab ? 1.f : -1.f)), 0.f, 1.f);
				m_tab_add = ImClamp(m_tab_add + (120.f * ImGui::GetIO().DeltaTime * (m_tab_count == m_active_tab ? 1.f : -1.f)), 0.f, 20.f);

				if (m_tab_alpha == 0.f)
					m_active_tab = m_tab_count;

				ImGui::PushStyleVar(ImGuiStyleVar_Alpha, m_tab_alpha);
				ImGui::SetCursorPos(ImVec2(160, 82 - m_tab_add));
				ImGui::MainBeginChild("content", ImVec2(525, 423), false, ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
				{
					if (m_active_tab == 0)
					{
						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Visuals");
							{
								ImGui::Checkbox("Box", &bbox);
								ImGui::Checkbox("Corner Box", &bCorner);
								ImGui::Checkbox("Name", &bname);
								//ImAdd::ToggleButton("Operator", &operatorESP);
								ImGui::Checkbox("Level", &bLevel);
								// ImAdd::ToggleButton("Weapon", &bWeapon);
								ImGui::Checkbox("Distance", &bdistance);
								ImGui::Checkbox("Health", &bhealth);
								ImGui::Checkbox("Shield", &bshield);
								ImGui::Checkbox("Seer Health", &bSeer);
								ImGui::Checkbox("Skeleton", &Skeleton);
								ImGui::Checkbox("Team Color", &bTeamCol);
								ImGui::Checkbox("SnapLines", &bSnaplines);
								ImGui::Checkbox("Player Info", &bInfo);
								//ImAdd::ToggleButton("Player Tab", &bInfo);
							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();

						ImGui::SameLine();

						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Settings", ImVec2(0, 204));
							{
								
								ImGui::SliderInt("Max Distance", &maxDistance, 0, 2500);
								ImGui::SliderInt("Seer Fov", &seerFov, 0, 100);
								//ImAdd::SliderFloat("Operator Fov", &TabSize, 0, 50);
								ImGui::Combo("Snapline Position", &snaplineSelection, snaplinePos, IM_ARRAYSIZE(snaplinePos));
								//ImGui::Combo("Glow Type", &GlowMethodInt, GlowMethods, IM_ARRAYSIZE(GlowMethods));
								ImGui::Checkbox("Ignore Downed", &bIgnoreDowned);
								ImGui::Checkbox("Ignore Team", &bTeamCheck);
								/*inline float opx, opy, opw, oph, opv, opz, opk, opi;
				inline float rounding;*/
				//PathFinder_texture
							}
							ImGui::EndChild();

							ImGui::BeginChild("Colors", ImVec2(0, 204));
							{
								ImGui::ColorEdit4("Box Color", NBoxCol);
								ImGui::ColorEdit4("Distance Color", DistCol);
								ImGui::ColorEdit4("Name Color", NameCol);
								ImGui::ColorEdit4("Weapon Color", weaponCol);
								ImGui::ColorEdit4("Skeleton Color", skeletonCol);
								ImGui::ColorEdit4("Snapline Color", snaplineCol);
								ImGui::ColorEdit4("Level Color", levelCol);

							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();
					}
					else if (m_active_tab == 1)
					{
						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Combat");
							{
								ImGui::Checkbox("Aimbot", &DoAimbot);
								ImGui::Checkbox("Render Fov", &renderFov);
								ImGui::Checkbox("Draw To Target", &bDrawTarget);
								//ImGui::Checkbox("Visibility Check", &AimbotVis);

								ImGui::Checkbox("No Recoil", &removeRecoil);
								ImGui::Checkbox("Trigger Bot", &bTrigger);
							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();

						ImGui::SameLine();

						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Settings", ImVec2(0, 204));
							{
								ImGui::SliderInt("Max Distance", &aimbotDist, 1, 500);
								ImGui::SliderInt("Aimbot Fov", &fov, 1, 100);
								ImGui::SliderInt("Aimbot Smoothing", &smothing, 1.0f, 20.0f);

								ImGui::Keybind("First Aimbot Key", &aimbotkey, a);
								ImGui::Keybind("Second Aimbot Key", &secondaimbotkey, a);

								ImGui::Keybind("Trigger Key", &triggerKey, a);

								ImGui::Combo("Hit Box", &hitbox, hitboxes, IM_ARRAYSIZE(hitboxes));
								ImGui::Checkbox("Ignore Team", &aimTeamCheck);

								ImGui::Text("Recoil");
								ImGui::SliderFloat("No Recoil X", &pitchSTR, 0.f, 1.f);
								ImGui::SliderFloat("No Recoil Y", &yawSTR, 0.f, 1.f);
							}
							ImGui::EndChild();

							ImGui::BeginChild("Colors", ImVec2(0, 204));
							{							
								ImGui::ColorEdit3("Fov Color", FOVCOLOR);
								ImGui::ColorEdit3("Target Line Color", TargetColor);

							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();
					}
					else if (m_active_tab == 2)
					{
						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Misc");
							{
								ImGui::Checkbox("Free Cam", &Freecam);
								//ImAdd::ToggleButton("Speed Hack", &SpeedHack);
								ImGui::Checkbox("Skin Changer", &SkinChange);
								ImGui::Checkbox("BHop", &bhop);
								ImGui::Checkbox("Super Glide", &autostraf);
								//ImGui::Checkbox("Spectator Count", &SpectatorCount);
								// ImAdd::ToggleButton("Show Fps", &ShowFps);
								ImGui::Checkbox("Auto Grapple", &autograple);
								//ImAdd::ToggleButton("Heirloom Changer", &heirloomchanger);
								ImGui::Checkbox("Force Crossplay Access", &ForceCrossPlayer);
							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();

						ImGui::SameLine();

						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Settings", ImVec2(0, 204));
							{
								ImGui::SliderInt("Skin ID", &skinId, 0, 13);
							//ImGui::SliderFloat("Brightness", &LPFOV, -180, 360);

								
							}
							ImGui::EndChild();
							ImGui::BeginChild("KeyBinds", ImVec2(0, 204));
							{
								// I//mAdd::KeyBind("Air Stuck Key", &AirStuckKey);
								 //ImAdd::KeyBind("ThirdPerson Key", &thridPersonKey);
								ImGui::Keybind("Free Cam Key", &freecamKey, a);
								ImGui::Keybind("Super Glide Key", &AutoStrafeeKey, a);
								ImGui::Keybind("Auto Grapple Key", &autograpleKey, a);
								ImGui::Keybind("Bhop Key", &bhopkey, a);

								ImGui::Keybind("Menu Key", &menukey, a);


							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();
					}
					else if (m_active_tab == 3)
					{
						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Item Settings");
							{
								ImGui::Checkbox("Item Esp", &bItemEsp);
								if (ImGui::Button("Weapons"))
								{
									weaponScreen = !weaponScreen;
									attachmentsScreen = false;
									armorScreen = false;
									otherScreen = false;
								}
								if (ImGui::Button("Attachments"))
								{
									attachmentsScreen = !attachmentsScreen;
									weaponScreen = false;
									armorScreen = false;
									otherScreen = false;
								}
								if (ImGui::Button("Armor"))
								{
									armorScreen = !armorScreen;
									attachmentsScreen = false;
									weaponScreen = false;
									otherScreen = false;
								}
								if (ImGui::Button("Other"))
								{
									otherScreen = !otherScreen;
									armorScreen = false;
									attachmentsScreen = false;
									weaponScreen = false;
								}
								if (weaponScreen && m_active_tab == 3)
								{
									ImGui::MultiCombo("Light", lightWeapons, lightOptions, 7);
									ImGui::MultiCombo("Heavy", heavyWeapons, heavyOptions, 5);
									ImGui::MultiCombo("Sniper", sniperWeapons, sniperOptions, 4);
									ImGui::MultiCombo("Shotgun", shotgunWeapons, shotgunOptions, 4);
									ImGui::MultiCombo("Energy", energyWeapons, energyOptions, 5);
									ImGui::MultiCombo("Specaial", specialWeapons, specialOptions, 4);
								}
								else if (attachmentsScreen && m_active_tab == 3)
								{
									ImGui::MultiCombo("Optics", opticAttachments, opticOptions, 10);
									ImGui::MultiCombo("Magazines", magazineAttachments, magazineOptions, 16);
									ImGui::MultiCombo("Stabilizers and Lazers", stabilizerAttachments, stabilizerOptions, 6);
									ImGui::MultiCombo("Stocks and Bolts", stockAttachments, stockOptions, 10);
									//ImGui::MultiCombo("Hop-Ups", hopAttachments, hopOptions, 3);
								}
								else if (armorScreen && m_active_tab == 3)
								{
									ImGui::MultiCombo("Helmet", helmetArmor, helmetOptions, 4);
									ImGui::MultiCombo("Body", bodyArmor, bodyOptions, 8);
									ImGui::MultiCombo("Knockdown", knochdownArmor, knockdownOptions, 4);
									ImGui::MultiCombo("Backpack", backpackArmor, backpackOptions, 4);
								}
								else if (otherScreen && m_active_tab == 3)
								{
									ImGui::MultiCombo("Meds", medsOther, medsOptions, 5);
									ImGui::MultiCombo("Grenades", nadeOther, nadeOptions, 3);
									ImGui::MultiCombo("Ammo", ammoOther, ammoOptions, 5);
									//ImGui::MultiCombo("Misc", miscOther, miscOptions, 6);
								}
								/*ImGui::MultiCombo("Weapons", weaponSelections, weaponList, IM_ARRAYSIZE(weaponList));
								ImGui::MultiCombo("Attachments", attachmentSelections, attachmentOptions, IM_ARRAYSIZE(attachmentOptions));
								ImGui::MultiCombo("Armor", armorSelections, armorOptions, IM_ARRAYSIZE(armorOptions));
								ImGui::MultiCombo("Other", ammoAndHealsSelections, ammoAndHealsOptions, IM_ARRAYSIZE(ammoAndHealsOptions));*/
							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();

						ImGui::SameLine();

						ImGui::BeginGroup();
						{
							ImGui::BeginChild("Colors", ImVec2(0, 204));
							{
								ImGui::ColorEdit3("Weapon Color", weaponColor);
								ImGui::ColorEdit3("Attachments Color", attachemtColor);
								ImGui::ColorEdit3("Armor Color", armorColor);
								ImGui::ColorEdit3("Heals Color", healsColor);
								ImGui::ColorEdit3("Ammo Color", ammoColor);
								ImGui::ColorEdit3("Grenade Color", grenadeColor);
							}
							ImGui::EndChild();

							ImGui::BeginChild("KeyBinds", ImVec2(0, 204));
							{


							}
							ImGui::EndChild();
						}
						ImGui::EndGroup();
					}
				}
				ImGui::MainEndChild();
				ImGui::PopStyleVar();
			}
		}
		ImGui::End();

	}
	if (Unlockall)
	{
		write<long>((uintptr_t)GetModuleHandle("r5apex.exe") + 0x02273330 + 0x6c, 1);
	}

	ImGui::GetForegroundDrawList()->AddCircle(ImVec2(GetSystemMetrics(0) / 2, GetSystemMetrics(1) / 2), 2.0f, ImColor(0, 255, 155, 255));
	//SYSTEMTIME st, lt;


//	GetSystemTime(&st);
	//GetLocalTime(&lt);
	//std::string HOOKPTR = "eSafe.Prv | Apex Legends Internal | " + std::to_string(int(lt.wYear)) + "/" + std::to_string(int(lt.wMonth)) + "/" + std::to_string(int(lt.wDay)) + " " + std::to_string(int(lt.wHour)) + ":" + std::to_string(int(lt.wMinute));
//	ImGui::GetForegroundDrawList()->PFontText(esp_font, 13, ImVec2(10, 0), ImColor(255, 255, 255, 255), HOOKPTR.c_str());
	if (watermark)
	{
		ImGui::GetBackgroundDrawList()->AddImage(icon_texture, ImVec2(-71, -80.6), ImVec2(355.5, 118.5));
	}
	RenderVisualsTest();

	
	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}
