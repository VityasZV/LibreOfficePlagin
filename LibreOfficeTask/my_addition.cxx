#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/lang/XMultiComponentFactory.hpp>
#include <com/sun/star/frame/XComponentLoader.hpp>

#include <com/sun/star/text/XTextDocument.hpp>
#include <com/sun/star/text/XText.hpp>


#include <com/sun/star/text/XTextTable.hpp>
#include <com/sun/star/text/XTextTablesSupplier.hpp>
#include <com/sun/star/text/XTextContent.hpp>

#include <com/sun/star/table/XCell.hpp>
#include <com/sun/star/table/XTableRows.hpp>
#include <com/sun/star/table/XCellRange.hpp>
#include <com/sun/star/table/XTable.hpp>

#include <com/sun/star/frame/Desktop.hpp>


#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <typeinfo>


using namespace com::sun::star::uno;
using namespace com::sun::star::lang;
using namespace com::sun::star::beans;
using namespace com::sun::star::frame;
using namespace com::sun::star::text;
using namespace com::sun::star::table;
using namespace com::sun::star::container;

using ::rtl::OUString;
using ::rtl::OUStringToOString;
using ::rtl::OString;

#include "my_addition.h"
#include <iostream>

std::string createName(uint32_t column, uint32_t row) {
    return (char)('A' + column) + std::to_string(row + 1);
}

void fillTable(Reference <XTextTable> table, int num_of_col, int num_of_row) {
    for (int x = 0; x < num_of_col; x++) {
        for (int y = 0; y < num_of_row; y++) {
            auto cell = table->getCellByName(OUString::createFromAscii(createName(x, y).c_str()));
            Reference<XText> cell_text(cell, UNO_QUERY);
            auto cell_val = [&x, &y](){
                return "row_" + std::to_string(y) + " colm_" + std::to_string(x);
            }();
            cell_text->setString(OUString::createFromAscii(cell_val.c_str()));
        }
    }
}

void createTable(Reference <XMultiServiceFactory> document, Reference <XText> text) {
    size_t num_of_row = std::rand() % 7 + 3;
    size_t num_of_col = std::rand() % 3 + 3;
    Reference <XTextTable> table(document->createInstance(OUString::createFromAscii("com.sun.star.text.TextTable")), UNO_QUERY);
    table->initialize(num_of_row, num_of_col);
    auto text_range = text->getEnd();
    Reference <XTextContent> text_content(table, UNO_QUERY);
    text->insertTextContent(text_range, text_content, (unsigned char) 0);
    fillTable(table, num_of_col, num_of_row);
}

void newDocumentCreation(Reference<XComponentContext> xContext){
    Reference<XMultiComponentFactory> xServiceManager = xContext->getServiceManager();
    Reference<XInterface> xDesktop = xServiceManager->createInstanceWithContext(OUString("com.sun.star.frame.Desktop"), xContext);
    Reference<XDesktop2> xDesktop2(xDesktop, UNO_QUERY);
    Reference<XComponent> xComponent = xDesktop2->loadComponentFromURL(OUString("private:factory/swriter"), // URL to the ods file
                                            OUString( "_blank" ), 0,
                                            Sequence < ::com::sun::star::beans::PropertyValue >());
    Reference <XTextDocument> text_document(xComponent, UNO_QUERY);
    Reference <XText> text = text_document->getText();
    Reference <XMultiServiceFactory> document(text_document, UNO_QUERY);
    size_t num_of_tables = std::rand() % 7 + 2;
    for (size_t i = 0; i < num_of_tables; i++) {
        auto text_cursor = text->createTextCursor();
        std::string table_name = "\nTable: ";
        table_name += std::to_string(i);
        text_cursor->gotoEnd(false);
        text_cursor->setString(OUString::createFromAscii(table_name.c_str()));
        createTable(document, text);
    }
}



size_t maxSizeOfTable(Reference<XTextTable> table) {
    auto cursor = table->createCursorByCellName(OUString::createFromAscii("A1"));
    uint32_t min_of_columns = 1;
    uint32_t min_of_rows = 1;
    while (cursor->goDown(1, false)) {
        ++min_of_columns;
    }
    while (cursor->goRight(1, false)) {
        ++min_of_rows;
    }
    return std::min(min_of_columns, min_of_rows);
}

void swapCells(const size_t &column, const size_t &row, Reference<XTextTable> table) {
    Reference<XCell> first_cell = table->getCellByName(OUString::createFromAscii(createName(column, row).c_str()));
    Reference<XCell> second_cell = table->getCellByName(OUString::createFromAscii(createName(row, column).c_str()));
    Reference<XText> first_cell_text(first_cell, UNO_QUERY);
    Reference<XText> second_cell_text(second_cell, UNO_QUERY);
    auto tmp = first_cell_text->getString();
    first_cell_text->setString(second_cell_text->getString());
    second_cell_text->setString(tmp);
}

void transpositionOfTable(Reference<XTextTable> table) {
    auto max_sq = maxSizeOfTable(table);
    for (size_t column = 0; column < max_sq; ++column) {
        for (size_t row = column; row < max_sq; ++row) {
            swapCells(column, row, table);
        }
    }
}


void tableTransposition(Reference<XTextDocument> text_document) {
    Reference<XTextTablesSupplier> table_helper(text_document, UNO_QUERY);
    auto text_tables = table_helper->getTextTables();
    auto tables_names = text_tables->getElementNames();
    for (size_t i = 0; i < tables_names.getLength(); ++i) {
        Reference<XTextTable> table(text_tables->getByName(tables_names[i]), UNO_QUERY);
        transpositionOfTable(table);
    }
}
