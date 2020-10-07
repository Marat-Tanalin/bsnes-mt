/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace bsnesMt::app {

using std::string, std::vector;

static const uint8_t quickStatesNumber = 25;
static const uint8_t recentGamesNumber = 25;

static const string title       = "bsnes-mt";
static const string version     = "1.3.3";
static const string copyYear    = u8"© 2020";
static const string authorEn    = "Marat Tanalin";
static const string authorRu    = u8"Марат Таналин";
static const string urlRoot     = "http://tanalin.com";
static const string pagePath    = "/projects/bsnes-mt/";
static const string articlePath = "/articles/integer-scaling/";
static const string urlEnPrefix = "/en";

static const string linkStartTagStart = "<a href=\"";
static const string linkStartTagEnd   = "\">";
static const string linkEndTag        = "</a>";

static const string bullet = u8"• ";
static const string space  = " ";

static const string pageUrlEn  = urlRoot + urlEnPrefix + pagePath;
static const string pageUrlRu  = urlRoot + pagePath;
static const string pageLinkEn = linkStartTagStart + pageUrlEn + linkStartTagEnd + pageUrlEn + linkEndTag;
static const string pageLinkRu = linkStartTagStart + pageUrlRu + linkStartTagEnd + pageUrlRu + linkEndTag;

static const string articleUrlEn = urlRoot + urlEnPrefix + articlePath;
static const string articleUrlRu = urlRoot + articlePath;

static const string infoEn = u8"Improved version of bsnes:\n\n" +
                             bullet + linkStartTagStart + articleUrlEn + linkStartTagEnd +
                                      u8"pixel-perfect integer-ratio scaling" + linkEndTag + ";\n" +
                             bullet + u8"precise 4:3 in the “Center” and “Scale” modes;\n" +
                             bullet + u8"compressed PNG screenshots;\n" +
                             bullet + u8"multilanguage user interface;\n" +
                             bullet + u8"built-in hotkeys for common actions;\n" +
                             bullet + u8"and more.\n\n" +
                             copyYear + space + authorEn + "\n" + pageLinkEn;

static const string infoRu = u8"Улучшенная версия bsnes:\n\n" +
                             bullet + linkStartTagStart + articleUrlRu + linkStartTagEnd +
                                      u8"целочисленное масштабирование без размытия" + linkEndTag + ";\n" +
                             bullet + u8"точное 4:3 в режимах «Center» и «Scale»;\n" +
                             bullet + u8"скриншоты в формате PNG со сжатием;\n" +
                             bullet + u8"многоязычный пользовательский интерфейс;\n" +
                             bullet + u8"встроенные горячие клавиши для частых действий;\n" +
                             bullet + u8"и многое другое.\n\n" +
                             copyYear + space + authorRu + "\n" + pageLinkRu;

static const string windowTitle = title + space + version;

static const vector<unsigned char> pngInfo = {
	0, 0, 0, 60, 116, 69, 88, 116, 83, 111, 102, 116, 119, 97, 114, 101, 0, 98,
	115, 110, 101, 115, 45, 109, 116, 32, 124, 32, 104, 116, 116, 112, 58, 47,
	47, 116, 97, 110, 97, 108, 105, 110, 46, 99, 111, 109, 47, 101, 110, 47,
	112, 114, 111, 106, 101, 99, 116, 115, 47, 98, 115, 110, 101, 115, 45, 109,
	116, 47, 136, 188, 137, 5
};

} // namespace bsnesMt::app