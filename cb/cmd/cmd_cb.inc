CMD:cb(playerid, params[])
{
    if (!Can->cb(playerid)) {
        return true;
    }

    extract params -> new blockid; else {
        return SendServerMessage(playerid, "/cb <id>");
    }

    if (!Validate->cb(playerid, blockid)) {
        return true;
    }

    SetPlayerBlock(playerid, blockid);

    Show->BlockMenu(playerid);
    return true;
}

/**
    ��� � ������� ����� �������� ���� ������ � ������ � �� ������ cmd ��� ���
*/
Access::cb(playerid)
{
    return true;
}

/**
    ��� ������������ ��������� � �.�.
*/
Request:cb(playerid, blockid)
{
    if (!IsValidBlock(blockid)) {
        SendServerMessage(playerid, "������� ������ ID �����");
        return false;
    }

    return true;
}

/**
    ���������� ������ ��� �������� � ������
*/
Resource:BlockMenu(world, blockid)
{
    new str[1024] = "{FFFFFF}";

    format(str, sizeof(str), "%s���\t[ %s ]", str, GetBlockName(world, blockid));
    format(str, sizeof(str), "%s������\t[ %s ]", str, GetBlockStatus(world, blockid)); // ���� ������� ���, ���� �������
    format(str, sizeof(str), "%s����\t[ %s ]", str, GetBlockBind(world, blockid)); // ���� ������� ���, ���� �������
    format(str, sizeof(str), "%s�������\t[ %d ]", str, GetBlockRulesCount(world, blockid)); // ���� ������� ���, ���� �������
    format(str, sizeof(str), "%���������\t[ %d ]", str, GetBlockCallbackCount(world, blockid)); // ���� ������� ���, ���� �������
    format(str, sizeof(str), "%�������\t[ %d ]", str, GetBlockCallbackCount(world, blockid)); // ���� ������� ���, ���� �������
    format(str, sizeof(str), "%���������\t[ %s ]", str, GetBlockActivation(world, blockid)); // ���� ������� ���, ���� �������

    return str;
}

Access::BlockMenu(playerid)
{
    return true;
}

Request:BlockMenu(playerid, response, listitem, inputtext)
{
    if (!response) {
        return false
    }

    return true;
}

/**
    ��� ������ ����������� �������
*/
View:BlockMenu(playerid)
{
    if (!Can->BlockMenu(playerid)) {
        return false;
    }

    return Dialog_Show(
        playerid,
        BlockMenu,
        DIALOG_STYLE_TABLIST,
        " ",
        Collect->BlockMenu(GetPlayerVirtualWorld(playerid), GetPlayerBlock(playerid))
        "Y",
        "X"
    );
}

Dialog:BlockMenu(playerid, response, listitem, inputtext[])
{
    if (!Can->BlockMenu(playerid)) {
        return false;
    }

    if (!Validate->BlockMenu(playerid, response, listitem, inputtext)) {
        return false;
    }

    return true;
}